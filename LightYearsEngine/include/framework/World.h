#pragma once
#include "Core.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace ly
{
	class Actor;
	class Application;		//forward declaration
	class World
	{
	public:
		World( Application* owner);
		virtual ~World();

		void TickInternal(float DeltaTime);
		void BeginPlayInternal();
		void Render(sf::RenderWindow& window) const;

		template <typename ActorType>
		weakPtr<ActorType> SpawnActor();

	private:
		Application* m_owningApp;
		bool m_BeganPlay;

		void BeginPlay();
		void Tick(float DeltaTime);

		ListArray<sharedPtr<Actor>> m_Actors;
		ListArray<sharedPtr<Actor>> m_PendingActors;

	};

	template <typename ActorType>
	weakPtr<ActorType> World::SpawnActor()
	{
		sharedPtr<ActorType> newActor{ new ActorType{ this } };
		m_PendingActors.push_back(newActor);
		return newActor;
	}
}
