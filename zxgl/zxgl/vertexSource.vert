#version 330 core                                        			
layout(location = 0) in vec3 aPos; 						
layout(location = 3) in vec3 aNormal;

uniform mat4 modeMat;
uniform mat4 viewMat;
uniform mat4 projMat;

out vec3 FragPos;
out vec3 Normal;

void main() {															
	gl_Position = projMat * viewMat * modeMat * vec4(aPos.xyz, 1.0);      
	Normal = mat3(modeMat) * aNormal;
} 