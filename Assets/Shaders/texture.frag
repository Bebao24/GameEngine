#version 330 core
out vec4 FragColor;

in vec2 v_TexCoords;
uniform sampler2D u_Texture; // Texture Id

void main()
{
    vec4 texColor = texture(u_Texture, v_TexCoords);
    FragColor = texColor;
}
