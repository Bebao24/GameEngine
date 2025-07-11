#version 330 core
layout (location = 0) in vec3 a_Pos;

uniform mat4 u_transformMatrix;
uniform mat4 u_projectionMatrix;

void main()
{
    gl_Position = u_projectionMatrix * u_transformMatrix * vec4(a_Pos, 1.0);
}

