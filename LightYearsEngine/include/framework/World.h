#pragma once
#include "Core.h"

namespace ly
{
	class Actor;
	class Application;		//forward declaration
	class World
	{
	public:
		World( Application* owner);
		void TickInternal(float DeltaTime);
		void BeginPlayInternal();

		virtual ~World();

		template <typename ActorType>
		weakPtr<ActorType> SpawnActor();

	private:
		Application* m_owningApp;
		bool m_BeganPlay;

		void BeginPlay();
		void Tick(float DeltaTime);

		List<sharedPtr<Actor>> m_Actors;
		List<sharedPtr<Actor>> m_PendingActors;

	};

	template <typename ActorType>
	weakPtr<ActorType> World::SpawnActor()
	{
		sharedPtr<ActorType> newActor{ new ActorType{ this } };
		m_PendingActors.push_back(newActor);
		return newActor;
	}
}
