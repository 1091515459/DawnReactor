#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target,glm::vec3 worldup) {
	Position = position;
	WorldUp = worldup;
	Forward = glm::normalize(target - position);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}
Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup)
{
	Position = position;
	WorldUp = worldup;
	Pitch = pitch;
	Yaw = yaw;
	Forward.x = glm::cos(glm::radians(pitch))* glm::sin(glm::radians(yaw));
	Forward.y = glm::sin(glm::radians(pitch));
	Forward.z = glm::cos(glm::radians(pitch)) * glm::cos(glm::radians(yaw));
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}
Camera::~Camera() {

}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Forward, WorldUp);
}

void Camera::ProcessMoustMovement(float deltaX, float deltaY)
{
	Pitch -= deltaY * zoomX;
	Yaw -= deltaX * zoomY;
	UpdateCameraVectors();
}

void Camera::UpdateCameraPos()
{
	//Position += glm::vec3(0, 0, -SpeedZ*zoomSpeedZ);
	Position += Forward * SpeedZ * zoomSpeed;
	Position += Right * SpeedX * zoomSpeed;
}

void Camera::UpdateCameraVectors()
{
	Forward.x = glm::cos(glm::radians(Pitch)) * glm::sin(glm::radians(Yaw));
	Forward.y = glm::sin(glm::radians(Pitch));
	Forward.z = glm::cos(glm::radians(Pitch)) * glm::cos(glm::radians(Yaw));
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}
