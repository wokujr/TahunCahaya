#pragma once

#include <SFML/Graphics.hpp>




namespace ly
{
	class Application
	{

	public:
		Application();
		void Run();

		void Tick(float DeltaTime);
		void Render();

	private:
		sf::RenderWindow m_Window;
		float m_TargetFrameWork;
		sf::Clock m_TickClock;
	};
}