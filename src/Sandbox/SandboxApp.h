#pragma once
#include <Engine/Engine.h>

class SandboxApp : public Engine::Application
{
public:
    SandboxApp();
    ~SandboxApp();

    void Start();
    void Update(float deltaTime);
    void OnEvent(Engine::Event& event) override;

private:
    Engine::Camera m_Camera;
    Engine::Texture m_Texture;
};


