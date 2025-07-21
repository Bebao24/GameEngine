#version 330 core
layout (location = 0) in vec3 a_Pos;
layout (location = 1) in vec2 a_TexCoords;

uniform mat4 u_transformMatrix;
uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;

out vec2 v_TexCoords;

void main()
{
    gl_Position = u_projectionMatrix * u_viewMatrix * u_transformMatrix * vec4(a_Pos, 1.0);
    v_TexCoords = a_TexCoords;
}

