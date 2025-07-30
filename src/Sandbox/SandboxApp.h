#pragma once
#include <Engine/Engine.h>

class SandboxApp : public Engine::Application
{
public:
    SandboxApp() = default;
    ~SandboxApp() = default;

    void Start();
    void Update(float deltaTime);
    void OnEvent(Engine::Event& event) override;

private:
    Engine::Texture m_Texture;
    Engine::Camera m_Camera;
};


