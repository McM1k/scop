#version 410 core
out vec4 FragColor;
flat in vec3 ourColor;

uniform sampler2D ourTexture;

void main()
{
	float grey;
	grey = (0.2125 * ourColor.x + 0.7154 * ourColor.y + 0.0721 * ourColor.z) / 1.2f;
	FragColor = vec4(grey, grey, grey, 1.0);
}