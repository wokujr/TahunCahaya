#pragma once

#include <framework/Application.h>

namespace ly
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void Tick(float DeltaTime) override;

	private:
		float m_Counter;
		weakPtr<Actor> actorToDestroy;
	};
}
