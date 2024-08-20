#pragma once
#include "Eevee/Core.h"
#include "Eevee/Layer.h"
#include "Eevee/Events/KeyEvent.h"
#include "Eevee/Events/MouseEvent.h"
#include "Eevee/Events/ApplicationEvent.h"

namespace Eevee {
	class EEVEE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();


		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;

	};
}