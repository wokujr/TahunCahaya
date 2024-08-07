#include "framework/World.h"

#include "framework/Core.h"
#include "framework/Actor.h"


namespace ly
{
	World::World(Application* owner)
		:
		m_owningApp(owner),
		m_BeganPlay(false),
		m_Actors(),
		m_PendingActors()
	{
		
	}

	World::~World() {}

	void World::TickInternal(float DeltaTime)
	{
		for (sharedPtr<Actor> actor : m_PendingActors)
		{
			m_Actors.push_back(actor);
			actor->BeginPlayInternal();
		}
		m_PendingActors.clear();

		for (sharedPtr<Actor> actor : m_Actors)
		{
			actor->Tick(DeltaTime);
		}
		

		Tick(DeltaTime);
	}

	void World::BeginPlayInternal()
	{
		if (!m_BeganPlay)
		{
			m_BeganPlay = true;
			BeginPlay();
		}
	}

	

	void World::BeginPlay()
	{
		LOG("Begin Play happening");
	}

	void World::Tick(float DeltaTime)
	{
		LOG("Tick at frame: %f", 1.f / DeltaTime);
	}
}
