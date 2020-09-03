#version 410 core
out vec4 FragColor;
flat in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D tex1;
uniform sampler2D tex2;
uniform sampler2D tex3;
uniform vec4 mixvalues;

void main()
{
	float grey;
	grey = (0.2125 * ourColor.x + 0.7154 * ourColor.y + 0.0721 * ourColor.z) / 1.2;
	FragColor = texture(tex1, TexCoord) * mixvalues.x
			  + texture(tex2, TexCoord) * mixvalues.y
			  + texture(tex3, TexCoord) * mixvalues.z
			  + grey * mixvalues.w;
}