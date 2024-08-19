#include <Eevee.h>

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
		PushOverlay(new Eevee::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Eevee::Application* Eevee::CreateApplication() {
	return new Sandbox;
}