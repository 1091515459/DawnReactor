#include<iostream>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

float vertices[] = {
	-0.5f, -0.5f, 0.0f, 	 //0
	 0.5f, -0.5f, 0.0f,	 //1
	 0.0f,  0.5f, 0.0f,	 //2
	 //0.5f, -0.5f, 0.0f,	 //
	 //0.0f,  0.5f, 0.0f,	 //
	 0.8f , 0.8f , 0.0f	 //3
};//后三个是故意写反的，下文有加反面剔除

unsigned int indices[] = {
	0,1,2,
	2,3,1
};

const char * vertexShaderSource =
"#version 330 core                                        				\n "
"layout(location = 0) in vec3 aPos; 								\n "
"void main() {																\n "
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}		\n ";

const char* fragmentShaderSource =
"#version 330 core                                    		\n "
"out vec4 FragColor;                                  		\n "
"void main() {													\n "
"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);}       	\n ";

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
	glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);//正面剔除
	//glCullFace(GL_BACK);//背面剔除
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//线框模式

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

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);//VAO不是必须的 VAO可以认为是个Key VAO不存储任何具体的订单值, VBO才存储, 当有多个VBO的时候 使用Key-VAO就会很方便
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glUseProgram(shaderProgram);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
