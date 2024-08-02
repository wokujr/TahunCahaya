#include "framework/World.h"

#include "framework/Core.h"


namespace ly
{
	World::World(Application* owner)
		:
		m_owningApp(owner),
		m_BeganPlay(false)
	{
		
	}
	World::~World() {}
	void World::TickInternal(float DeltaTime)
	{
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
