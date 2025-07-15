#version 330 core

out vec4 FragColor;

uniform vec4 u_Color;
in vec2 v_LocalPos;

void main()
{
    vec2 center = vec2(0.5, 0.5);
    float dist = length(v_LocalPos - center);

    if (dist > 0.5)
    {
        discard; // Make outside transparent
    }

    FragColor = u_Color;
}

