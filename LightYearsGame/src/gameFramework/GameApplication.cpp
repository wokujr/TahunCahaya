#include <gameFramework/GameApplication.h>
#include "framework/Actor.h"


ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		:
		Application(720, 1080, "Tahun Cahaya", sf::Style::Titlebar | sf::Style::Close)
	{
		weakPtr<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy.lock()->SetTexture("E:/Project/C++/LightYears/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
		m_Counter = 0;

	}

	void GameApplication::Tick(float DeltaTime)
	{
		m_Counter += DeltaTime;
		if (m_Counter > 2.f)
		{
			if (!actorToDestroy.expired())
			{
				actorToDestroy.lock()->Destroy();

			}
		}
	}
}

