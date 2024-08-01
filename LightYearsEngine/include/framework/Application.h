#pragma once

#include <SFML/Graphics.hpp>




namespace ly
{
	class Application
	{

	public:
		Application();
		void Run();

		void TickInternal(float DeltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float DeltaTime);

	private:
		sf::RenderWindow m_Window;
		float m_TargetFrameWork;
		sf::Clock m_TickClock;
	};
}