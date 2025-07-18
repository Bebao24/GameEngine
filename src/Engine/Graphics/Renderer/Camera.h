#pragma once
#include <glm/glm.hpp>
#include <Engine/Math/Math.h>

namespace Engine
{
    class Camera
    {
    public:
        Camera(float left, float right, float top, float bottom);
        ~Camera() = default;

        Camera() = default;

        void SetPosition(const Math::Vector2& position);
        void SetRotation(float rotation);

        Math::Vector2 GetPosition() const;
        float GetRotation() const { return m_Rotation; }

        const glm::mat4& GetProjection() const { return m_Proj; }
        const glm::mat4& GetView() const { return m_View; }

    private:
        void RecalculateMatrix();

        glm::mat4 m_Proj;
        glm::mat4 m_View;

        glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
        float m_Rotation = 0.0f;
    };
}

