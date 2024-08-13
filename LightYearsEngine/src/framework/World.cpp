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

	World::~World() = default;

	void World::TickInternal(float DeltaTime)
	{
		for (sharedPtr<Actor> actor : m_PendingActors)
		{
			m_Actors.push_back(actor);
			actor->BeginPlayInternal();
		}
		m_PendingActors.clear();

		for (auto iteration = m_Actors.begin(); iteration != m_Actors.end(); )
		{
			if (iteration->get()->IsPendingDestroy())
			{
				iteration = m_Actors.erase(iteration);
			}
			else
			{
				iteration->get()->TickInternal(DeltaTime);
				++iteration;
			}
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
		LOG("World Cpp is Tick at frame: %f", 1.f / DeltaTime);
	}

	void World::Render(sf::RenderWindow& window) const
	{
		for (auto& actors : m_Actors)
		{
			actors->Render(window);
		}
	}


}
