#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 normalize;
uniform mat4 translateOrigin;
uniform mat4 translateZ;

void main() {
	gl_Position = translateZ * translateOrigin * normalize * vec4( position, 1.0f );

	// TODO: write soft code to find texture origin
	TexCoord = texCoord; // vec2( texCoord.x, 1.0f - texCoord.y );
}

