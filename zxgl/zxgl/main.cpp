#include<iostream>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"shaderClass1.h"
#include "stb_image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

//float vertices[] = {
//	//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
//		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
//		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
//		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
//		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
//};

float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

unsigned int indices[] = {
	0,1,2,
	2,3,0
};

glm::vec3 cubePositions[] = {
  glm::vec3(0.0f, 0.0f,  0.0f),
  glm::vec3(2.0f,  5.0f, -15.0f),
  glm::vec3(-1.5f, -2.2f, -2.5f),
  glm::vec3(-3.8f, -2.0f, -12.3f),
  glm::vec3(2.4f, -0.4f, -3.5f),
  glm::vec3(-1.7f,  3.0f, -7.5f),
  glm::vec3(1.3f, -2.0f, -2.5f),
  glm::vec3(1.5f,  2.0f, -2.5f),
  glm::vec3(1.5f,  0.2f, -1.5f),
  glm::vec3(-1.3f,  1.0f, -1.5f)
};

//const char * vertexShaderSource =
//"#version 330 core                                        				\n "
//"layout(location = 0) in vec3 aPos; 								\n "
//"layout(location = 1) in vec3 aColor; 							\n "
//"out vec4 vertexColor;                                                 \n "
//"void main() {																\n "
//"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);       \n "
//"	vertexColor = vec4(aColor.x, aColor.y, aColor.z, 1.0);												\n "
//"}																					\n ";
//
//const char* fragmentShaderSource =
//"#version 330 core                                    		\n "
//"in vec4 vertexColor;                                 		\n "
//"uniform vec4 ourColor;									\n "
//"out vec4 FragColor;                                        \n "
//"void main() {													\n "
//"	FragColor = vertexColor;}								\n ";

void processInput(GLFWwindow*window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//open GLFW Window
	GLFWwindow* window = glfwCreateWindow(800, 600, "ANODE face", NULL, NULL);

	if (window == NULL)
	{
		printf("open window fail");
		glfwTerminate();
		return -1;

	}
	glfwMakeContextCurrent(window);

	//Init GLFW
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		printf("init GLEW failed");
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, 800, 600);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);//正面剔除
	//glCullFace(GL_BACK);//背面剔除
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//线框模式
	glEnable(GL_DEPTH_TEST);

	shaderClass1* myshader = new shaderClass1("vertexSource.txt", "fragmentSource.txt");



	////主要用法
	//unsigned int VAO[10];
	//glGenVertexArrays(10, VAO);
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	////主要用法
	//unsigned int VBO[10];
	//glGenBuffers(10, VBO);
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//unsigned int vertexShader;
	//vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//glCompileShader(vertexShader);

	//unsigned int fragmentShader;
	//fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//glCompileShader(fragmentShader);

	//unsigned int shaderProgram;
	//shaderProgram = glCreateProgram();
	//glAttachShader(shaderProgram, vertexShader);
	//glAttachShader(shaderProgram, fragmentShader);
	//glLinkProgram(shaderProgram);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);

	unsigned int TexBufferA;
	glGenTextures(1, &TexBufferA);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, TexBufferA);
	//加载并生成纹理
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		printf("Failed to load texture");
	}
	stbi_image_free(data);

	unsigned int TexBufferB;
	glGenTextures(1, &TexBufferB);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, TexBufferB);
	//加载并生成纹理
	unsigned char* data2 = stbi_load("美女.png", &width, &height, &nrChannels, 0);
	if (data2) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		printf("Failed to load texture");
	}
	stbi_image_free(data2);

	//calculate our transformation matrix here.

	glm::mat4 trans;
	//trans = glm::rotate(trans, glm::radians(90.0f),glm::vec3(0.0f, 0, 1.0f));
	//trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
	//trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0));
	//trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0, 0, 1.0f));

	glm::mat4 modeMat;
	modeMat = glm::rotate(modeMat, glm::radians(0.0f), glm::vec3(0, 1.0f, 1.0f));
	glm::mat4 viewMat;
	viewMat = glm::translate(viewMat, glm::vec3(0, 0, -3.0f));
	glm::mat4 projMat;
	projMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	while (!glfwWindowShouldClose(window))
	{


		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, TexBufferA);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, TexBufferB);
		glBindVertexArray(VAO);//VAO不是必须的 VAO可以认为是个Key VAO不存储任何具体的订单值, VBO才存储, 当有多个VBO的时候 使用Key-VAO就会很方便
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		//float timeValue = glfwGetTime();
		//float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		//int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		//glUseProgram(shaderProgram);
		//glUniform4f(vertexColorLocation, 0, greenValue, 0, 1.0f);

		int modelnumber = 10;

		for (int i = 0; i < modelnumber; i++)
		{
			glm::mat4 model;
			model = glm::translate(model, cubePositions[i]);
			myshader->use();
			glUniform1i(glGetUniformLocation(myshader->ID, "ourTexture"), 0);
			glUniform1i(glGetUniformLocation(myshader->ID, "ourFace"), 1);
			//glUniformMatrix4fv(glGetUniformLocation(myshader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
			glUniformMatrix4fv(glGetUniformLocation(myshader->ID, "modeMat"), 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(glGetUniformLocation(myshader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
			glUniformMatrix4fv(glGetUniformLocation(myshader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
