#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera
{
public :
	Camera(glm::vec3 position, glm::vec3 target,glm::vec3 worldup);
	Camera(glm::vec3 position, float patch, float yaw, glm::vec3 worldup);
	~Camera();

	glm::vec3 Position;
	glm::vec3 Forward;
	glm::vec3 Right;
	glm::vec3 Up;
	glm::vec3 WorldUp;
	float Pitch;
	float Yaw;
	float zoomX=0.15;//减少鼠标x轴晃动的幅度
	float zoomY = 0.15;//减少鼠标y轴晃动的幅度
	float zoomSpeed = 0.05;//减少鼠标前进后退的幅度
	float SpeedZ = 0;
	float SpeedX = 0;

	glm::mat4 GetViewMatrix();
	void ProcessMoustMovement(float deltaX, float deltaY);
	void UpdateCameraPos();
private:
	void UpdateCameraVectors();
};


