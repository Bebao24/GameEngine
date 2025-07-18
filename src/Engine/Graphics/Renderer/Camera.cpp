#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Engine
{
    Camera::Camera(float left, float right, float top, float bottom)
    {
        m_Proj = glm::ortho(left, right, bottom, top);
        m_View = glm::mat4(1.0f);
    }

    void Camera::SetPosition(const Math::Vector2& position)
    {
        m_Position.x = position.x;
        m_Position.y = position.y;
        m_Position.z = 0.0f;

        RecalculateMatrix();
    }

    void Camera::SetRotation(float rotation)
    {
        m_Rotation = rotation;
        RecalculateMatrix();
    }

    Math::Vector2 Camera::GetPosition() const
    {
        Math::Vector2 retPos(m_Position.x, m_Position.y);
        return retPos;
    }

    void Camera::RecalculateMatrix()
    {
        glm::mat4 trans = glm::translate(glm::mat4(1.0f), m_Position); // Translation
        trans *= glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
        
        // Inverse the matrix
        // Basically moving the camera (by moving things in the reverse direction)
        m_View = glm::inverse(trans);
    }
}


