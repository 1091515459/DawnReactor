#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

int main2() {
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);//��תͼ���OpenGL��ʶ���Y��ͬ����
	unsigned char*data = stbi_load("��.png", &width, &height, &nrChannels, 0);

	for (size_t i = 0; i < 100; i++)
	{
		std::cout << (int)data[i] << std::endl;
	}

	stbi_image_free(data);//�ͷ�ͼƬ

	while (true) {

	} 

	return 0;
}