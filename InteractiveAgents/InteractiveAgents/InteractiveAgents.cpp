#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include "grid.h"

using namespace sf;

int main()
{
	const int columns = 9;
	const int rows = 9;

	RenderWindow *window = new RenderWindow(VideoMode(1205, 805), "Scoop");

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		
		grid(window, 10);
		
		window->display();
	}
	return 0;
}