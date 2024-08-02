#pragma once

namespace ly
{
	class Application; //forward declaration
	class World
	{
	public:
		World( Application* owner);
		void TickInternal(float DeltaTime);
		void BeginPlayInternal();

		virtual ~World();

	private:
		Application* m_owningApp;
		bool m_BeganPlay;

		void BeginPlay();
		void Tick(float DeltaTime);

	};
}
