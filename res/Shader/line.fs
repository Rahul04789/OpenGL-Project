#version 330 core
in vec3 color;

out vec4 Color;

void main()
{
    Color = vec4(color, 1.0f);
}
