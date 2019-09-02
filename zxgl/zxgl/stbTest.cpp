#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

int main2() {
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);//翻转图像和OpenGL所识别的Y轴同方向
	unsigned char*data = stbi_load("打开.png", &width, &height, &nrChannels, 0);

	for (size_t i = 0; i < 100; i++)
	{
		std::cout << (int)data[i] << std::endl;
	}

	stbi_image_free(data);//释放图片

	while (true) {

	} 

	return 0;
}