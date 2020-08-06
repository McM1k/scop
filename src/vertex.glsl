#version 410 core
layout (location = 0) in vec3 aPos;
flat out vec3 ourColor;
uniform mat4 transform;
void main()
{
	gl_Position = transform * vec4(aPos, 1.0);
	ourColor = vec3(aPos * 0.4f + 0.4f);
}