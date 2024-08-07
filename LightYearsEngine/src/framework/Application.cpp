#include "framework/Application.h"

#include "framework/Core.h"
#include "framework/World.h"


namespace ly
{
	Application::~Application() = default;

	Application::Application()
		:
		m_Window{ sf::VideoMode(1024, 1440), "Tahun Chaya" },
		m_TargetFrameWork(60.f),
	currentWorld(nullptr)
	{
		
	}

	void Application::Run()
	{
		m_TickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / m_TargetFrameWork;



		while (m_Window.isOpen())
		{
			sf::Event windowEvent;
			while (m_Window.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					m_Window.close();
				}
			}

			// This will calculate the current frame rate based on machine,  so basically it if accumulated time is bigger than targetDeltaTime it will subtract until it less than accumulatedTime so that's why it can be double the time depend on the actual machine... i guess?

			accumulatedTime += m_TickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
				
			}
			// to know the actual frame rate of our machine?
			/*float frameDeltaTime = m_TickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			std::cout << "Frame rate: " << 1.f / frameDeltaTime <<std::endl;*/
		}
	}

	void Application::TickInternal(float DeltaTime)
	{

		Tick(DeltaTime);
		if (currentWorld)
		{
			currentWorld->TickInternal(DeltaTime);
		}

	}

	void Application::RenderInternal()
	{
		m_Window.clear();

		Render();

		m_Window.display();

	}

	void Application::Render()
	{
		sf::RectangleShape rectangle(sf::Vector2f(100, 100));
		rectangle.setFillColor(sf::Color::Cyan);
		rectangle.setOrigin(50.f, 50.f);
		rectangle.setPosition(m_Window.getSize().x / 2.f, m_Window.getSize().y / 2.f);

		m_Window.draw(rectangle);
	}

	void Application::Tick(float DeltaTime)
	{

	}
}

