#pragma once
#include "Object.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace ly
{
	class World;

	class Actor : public Object
	{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		virtual ~Actor();

		void BeginPlayInternal();
		void TickInternal(float DeltaTime);

		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);

		void SetTexture(const std::string& texturePath);
		void Render(sf::RenderWindow& window) const;

	private:
		World* m_OwningWorld;
		bool m_HasBeganPlay;

		sf::Sprite m_Sprite;
		sf::Texture m_Texture;

	};

}
