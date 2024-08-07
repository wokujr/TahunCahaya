#include <gameFramework/GameApplication.h>
#include "framework/Actor.h"


ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
	{
		weakPtr<World> newActor = LoadWorld<World>();
		newActor.lock()->SpawnActor<Actor>();
	}
}

