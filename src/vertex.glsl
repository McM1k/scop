#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
flat out vec3 ourColor;
out vec2 TexCoord;
uniform mat4 transform;
void main()
{
	gl_Position = transform * vec4(aPos, 1.0);
	ourColor = vec3(aPos * 2 + 0.4);
	TexCoord = aTex;
}