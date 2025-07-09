CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++20 -I src/ -I src/vendor/glad/include

CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11 -I src/ -I src/vendor/glad/include

LD = g++
LDFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

CPP_SOURCES := $(shell find src -name "*.cpp")
CPP_OBJECTS := $(patsubst src/%.cpp, build/objects/cpp/%.o, $(CPP_SOURCES))

C_SOURCES := $(shell find src -name "*.c")
C_OBJECTS := $(patsubst src/%.c, build/objects/c/%.o, $(C_SOURCES))

CPP_HEADERS := $(shell find src -name "*.h")
C_HEADERS := $(shell find src -name "*.h")

.PHONY: all engine clean
all: engine

engine: build/engine
build/engine: $(CPP_OBJECTS) $(C_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

build/objects/cpp/%.o: src/%.cpp $(CPP_HEADERS) Makefile
	@ mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

build/objects/c/%.o: src/%.c $(C_HEADERS) Makefile
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf build
