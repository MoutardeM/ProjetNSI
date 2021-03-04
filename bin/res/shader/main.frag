#version 120

varying vec3 passNormal;
varying vec3 passFragPos;

void main()
{
    vec3 groundColor = vec3(1.0, 0.0, 0.0);
	vec3 lightColor = vec3(1.0, 1.0, 1.0);
	vec3 lightPosition = vec3(0.0, 1000.0, 0.0);

	//========================AMBIANT LIGHT==============
	float ambiantIntensity = 0.1f;

	vec3 ambiantColor = lightColor*ambiantIntensity;

	//=======================DIFFUSE LIGHT===============
	float diffuseIntensity = max(dot(normalize(lightPosition - passFragPos), passNormal), 0.0);

	vec3 diffuseColor = lightColor*diffuseIntensity;

	//======================FINAL FRAG COLOR=============
	vec3 finalColor = (ambiantColor + diffuseColor)*groundColor;
	gl_FragColor = vec4(finalColor, 1.0);
}
