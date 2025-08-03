CXX = g++
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	echo "This is MacOS"
	CXXFLAGS = -Wall -Wextra -O2 -std=c++20 -MMD -MP -I /opt/homebrew/include -I src/ -I src/vendor/glad/include -I src/vendor -I src/vendor/stb_image -I src/vendor/stb_truetype
	CFLAGS = -Wall -Wextra -O2 -std=c11 -MMD -MP -I /opt/homebrew/include -I src/ -I src/vendor/glad/include -I src/vendor -I src/vendor/stb_image
else
	CXXFLAGS = -Wall -Wextra -O2 -std=c++20 -MMD -MP -I src/ -I src/vendor/glad/include -I src/vendor -I src/vendor/stb_image -I src/vendor/stb_truetype
	CFLAGS = -Wall -Wextra -O2 -std=c11 -MMD -MP -I src/ -I src/vendor/glad/include -I src/vendor -I src/vendor/stb_image
endif


CC = gcc

LD = g++
LDFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

CPP_SOURCES := $(shell find src -name "*.cpp")
CPP_OBJECTS := $(patsubst src/%.cpp, build/objects/cpp/%.o, $(CPP_SOURCES))

C_SOURCES := $(shell find src -name "*.c")
C_OBJECTS := $(patsubst src/%.c, build/objects/c/%.o, $(C_SOURCES))

.PHONY: all engine clean
all: engine

engine: build/engine
build/engine: $(CPP_OBJECTS) $(C_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

build/objects/cpp/%.o: src/%.cpp Makefile
	@ mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

build/objects/c/%.o: src/%.c Makefile
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf build

-include $(CPP_OBJECTS:.o=.d) $(C_OBJECTS:.o=.d)


