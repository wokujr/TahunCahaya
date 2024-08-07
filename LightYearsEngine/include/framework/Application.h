#pragma once

#include <SFML/Graphics.hpp>

#include "Core.h"
#include "framework/World.h"

namespace ly
{
	class World;		//forward declaration
	class Application
	{

	public:
		virtual ~Application();
		Application();
		void Run();

		template <typename WorldType>
		weakPtr<World> LoadWorld();

	private:
		void TickInternal(float DeltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float DeltaTime);


		sf::RenderWindow m_Window;
		float m_TargetFrameWork;
		sf::Clock m_TickClock;

		sharedPtr<World> currentWorld;
	};

	template <typename WorldType>
	weakPtr<World> Application::LoadWorld()
	{
		sharedPtr<WorldType> newWorld{ new WorldType{this} };
		currentWorld = newWorld;
		currentWorld->BeginPlayInternal();
		return newWorld;
	}
}
