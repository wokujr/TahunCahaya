
#include<iostream>

#include "framework/Application.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

int main()
{
	//IDK but... with smart pointer... idk for sure leave it here.
	/*std::unique_ptr<ly::Application> App{ new ly::Application() };
	App->Run();*/

	//Allocate on heap
	ly::Application* App = new ly::Application();
	App->Run();


	return 0;
}
