#include "framework/Actor.h"

#include "framework/Core.h"

ly::Actor::Actor(World* owningWorld)
	:
	m_OwningWorld(owningWorld),
	m_HasBeganPlay(false)
{
	
}

void ly::Actor::BeginPlayInternal()
{
	if (!m_HasBeganPlay)
	{
		m_HasBeganPlay = true;
		BeginPlay();
	}
}

void ly::Actor::BeginPlay()
{
	LOG("Actor Began Play");
}

void ly::Actor::Tick(float DeltaTime)
{
	LOG("Actor TIck Began");
}
