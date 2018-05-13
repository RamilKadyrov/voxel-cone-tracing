#include "PerspectiveCamera.h"
#include "glm/gtc/matrix_transform.hpp"

PerspectiveCamera::PerspectiveCamera(float _fov, float _aspect, float _near, float _far)
	: Camera(glm::perspective(_fov, _aspect, _near, _far)) {}
