#include <SFML/Graphics.hpp>
#include <iostream>

#include "InteractiveEntity.h"
#include "grid.h"

using namespace sf;

int main()
{
	const int columns = 9;
	const int rows = 9;

	RenderWindow *window = new RenderWindow(VideoMode(1205, 805), "Scoop");

	InteractiveEntity *entity = new InteractiveEntity();

	grid activeGrid = grid(window, 10);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();			
			}
		}

		window->clear();

		activeGrid.draw();

		activeGrid.listOfNodes[2].nodeType = node::start;

		activeGrid.listOfNodes[300].nodeType = node::goal;		

		//entity->think();

		window->display();
	}
	return 0;
}