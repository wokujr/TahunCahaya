#include "framework/Actor.h"

#include "framework/Core.h"
#include "framework/Object.h"

ly::Actor::~Actor()
{
	LOG("Actor Destroyed");
}

ly::Actor::Actor(World* owningWorld, const std::string& texturePath)
	:
	m_OwningWorld(owningWorld),
	m_HasBeganPlay(false),
	m_Sprite(),
	m_Texture()
{
	SetTexture(texturePath);
}

void ly::Actor::BeginPlayInternal()
{
	if (!m_HasBeganPlay)
	{
		m_HasBeganPlay = true;
		BeginPlay();
	}
}

void ly::Actor::TickInternal(float DeltaTime)
{
	if (!IsPendingDestroy())
	{
		Tick(DeltaTime);
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

void ly::Actor::SetTexture(const std::string& texturePath)
{
	m_Texture.loadFromFile(texturePath);
	m_Sprite.setTexture(m_Texture);

	//Reset sprite texture to make sure it render, it read which corner, meaning up-left corner to bottom-right corner
	int textureWidth = m_Texture.getSize().x;
	int textureHeight = m_Texture.getSize().y;
	m_Sprite.setTextureRect(sf::IntRect{ sf::Vector2i{},sf::Vector2i{textureWidth, textureHeight} } );
}

void ly::Actor::Render(sf::RenderWindow& window) const
{
	if (IsPendingDestroy())
	{
		return;
	}

	window.draw(m_Sprite);
}
