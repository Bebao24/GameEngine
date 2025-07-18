#version 330 core
layout (location = 0) in vec3 a_Pos;

uniform mat4 u_transformMatrix;
uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;

out vec2 v_LocalPos;

void main()
{
    gl_Position = u_projectionMatrix * u_viewMatrix * u_transformMatrix * vec4(a_Pos, 1.0);
    v_LocalPos = a_Pos.xy;
}

