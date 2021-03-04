#version 120

attribute vec3 vertex;
attribute vec3 normal;

uniform mat4 projection;
uniform mat4 view;

varying vec3 passNormal;
varying vec3 passFragPos;

void main()
{
    gl_Position = projection*view*vec4(vertex, 1.0);

    passNormal = normal;
	passFragPos = vertex;
}
