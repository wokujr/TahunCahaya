#include "framework/Object.h"

#include "framework/Core.h"


namespace ly
{
	Object::Object()
		:
		m_IsPendingDestroyed(false)

	{
		
	}

	Object::~Object()
	{
		LOG("Object Destroyed");
	}


	void Object::Destroy()
	{
		m_IsPendingDestroyed = true;

	}
}
