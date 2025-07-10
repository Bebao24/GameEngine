#version 330 core
layout (location = 0) in vec3 a_Pos;

out vec4 vertColor;

void main()
{
    gl_Position = vec4(a_Pos, 1.0);
    vertColor = vec4(1.0, 0.0, 0.0, 1.0);
}

