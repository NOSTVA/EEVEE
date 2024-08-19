#pragma once
#include "evpch.h"

#ifdef EV_PLATFORM_WINDOWS

extern Eevee::Application* Eevee::CreateApplication();

int main(int argc, char** argv)
{
	Eevee::Log::Init();

	auto app = Eevee::CreateApplication();
	app->Run();
	delete app;
}

#endif
