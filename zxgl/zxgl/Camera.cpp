#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target,glm::vec3 worldup) {
	Position = position;
	WorldUp = worldup;
	Forward = glm::normalize(target - position);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}
Camera::Camera(glm::vec3 position, float patch, float yaw, glm::vec3 worldup)
{
	Position = position;
	WorldUp = worldup;
	Forward.x = glm::cos(glm::radians(patch))* glm::sin(glm::radians(yaw));
	Forward.y = glm::sin(glm::radians(patch));
	Forward.z = glm::cos(glm::radians(patch)) * glm::cos(glm::radians(yaw));
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}
Camera::~Camera() {

}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Forward, WorldUp);
}
