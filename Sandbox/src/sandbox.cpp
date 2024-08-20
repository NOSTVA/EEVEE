#include <Eevee.h>

#include "imgui/imgui.h"

class ExampleLayer : public Eevee::Layer
{
public:
	ExampleLayer() : Layer("Exmaple") {}

	void OnUpdate() override
	{
		if (Eevee::Input::IsKeyPressed(EV_KEY_W)) {
			EV_INFO("W is Pressed");
		}
	}

	void OnImGuiRender()
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello world");
		ImGui::End();
	}

	void OnEvent(Eevee::Event& event) override
	{
		//EV_TRACE(event.ToString());
	}
};

class Sandbox : public Eevee::Application {
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Eevee::Application* Eevee::CreateApplication() {
	return new Sandbox;
}