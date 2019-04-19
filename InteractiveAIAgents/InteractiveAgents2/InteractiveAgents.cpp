#include <SFML/Graphics.hpp>
#include <iostream>

#include "InteractiveEntity.h"
#include "grid.h"

using namespace sf;

int main()
{
	RenderWindow *window = new RenderWindow(VideoMode(1205, 805), "Scoop");

	InteractiveEntity *entity = new InteractiveEntity();

	sf::Sprite backgroundS;
	sf::Texture backgoundT;
	backgoundT.loadFromFile("Assets\\island2.png");
	backgroundS.setTexture(backgoundT);

	grid activeGrid = grid(window, 10);
	//activeGrid.startNode = &activeGrid.listOfNodes[10];

	//entity->entitySprite.setPosition(activeGrid.startNode->posX, activeGrid.startNode->posY);
	entity->entitySprite.setPosition(500, 500);

	activeGrid.listOfNodes[300].nodeType = node::goal;

	activeGrid.listOfNodes[95].nodeType = node::obstacle;
	activeGrid.listOfNodes[94].nodeType = node::obstacle;
	activeGrid.listOfNodes[93].nodeType = node::obstacle;
	activeGrid.listOfNodes[92].nodeType = node::obstacle;
	activeGrid.listOfNodes[91].nodeType = node::obstacle;
	activeGrid.listOfNodes[90].nodeType = node::obstacle;
	activeGrid.listOfNodes[89].nodeType = node::obstacle;
	activeGrid.listOfNodes[88].nodeType = node::obstacle;
	activeGrid.listOfNodes[87].nodeType = node::obstacle;
	activeGrid.listOfNodes[86].nodeType = node::obstacle;
	activeGrid.listOfNodes[85].nodeType = node::obstacle;
	activeGrid.listOfNodes[84].nodeType = node::obstacle;

	activeGrid.listOfNodes[100].nodeType = node::obstacle;
	activeGrid.listOfNodes[116].nodeType = node::obstacle;
	activeGrid.listOfNodes[132].nodeType = node::obstacle;
	activeGrid.listOfNodes[148].nodeType = node::obstacle;
	activeGrid.listOfNodes[164].nodeType = node::obstacle;
	activeGrid.listOfNodes[180].nodeType = node::obstacle;
	activeGrid.listOfNodes[196].nodeType = node::obstacle;
	activeGrid.listOfNodes[212].nodeType = node::obstacle;
	activeGrid.listOfNodes[228].nodeType = node::obstacle;
	activeGrid.listOfNodes[244].nodeType = node::obstacle;

	activeGrid.listOfNodes[214].nodeType = node::obstacle;
	activeGrid.listOfNodes[230].nodeType = node::obstacle;
	activeGrid.listOfNodes[246].nodeType = node::obstacle;
	activeGrid.listOfNodes[262].nodeType = node::obstacle;
	activeGrid.listOfNodes[278].nodeType = node::obstacle;
	activeGrid.listOfNodes[294].nodeType = node::obstacle;
	activeGrid.listOfNodes[310].nodeType = node::obstacle;
	activeGrid.listOfNodes[326].nodeType = node::obstacle;

	activeGrid.listOfNodes[326 + 16].nodeType = node::obstacle;
	activeGrid.listOfNodes[326 + 16 + 16].nodeType = node::obstacle;
	activeGrid.listOfNodes[326 + 16 + 16 + 16].nodeType = node::obstacle;

	activeGrid.listOfNodes[215].nodeType = node::obstacle;
	activeGrid.listOfNodes[216].nodeType = node::obstacle;
	activeGrid.listOfNodes[217].nodeType = node::obstacle;
	activeGrid.listOfNodes[218].nodeType = node::obstacle;
	activeGrid.listOfNodes[219].nodeType = node::obstacle;
	activeGrid.listOfNodes[220].nodeType = node::obstacle;
	activeGrid.listOfNodes[221].nodeType = node::obstacle;

	activeGrid.listOfNodes[221+16].nodeType = node::obstacle;
	activeGrid.listOfNodes[221+16 + 16].nodeType = node::obstacle;
	activeGrid.listOfNodes[221+16 + 16 + 16].nodeType = node::obstacle;
	activeGrid.listOfNodes[221+16 + 16 + 16 + 16].nodeType = node::obstacle;
	activeGrid.listOfNodes[221+16 + 16 + 16 + 16 + 16].nodeType = node::obstacle;
	activeGrid.listOfNodes[221+16 + 16 + 16 + 16 + 16 + 16].nodeType = node::obstacle;
	activeGrid.listOfNodes[221+16 + 16 + 16 + 16 + 16 + 16 + 16].nodeType = node::obstacle;



	window->setFramerateLimit(10);

	//std::cout << "Start Node: Row: " << activeGrid.startNode->rowVal << " Col: " << activeGrid.startNode->colVal << std::endl;

	//main loop for the program
	while (window->isOpen())
	{
		//event handler
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();
			}
		}

		window->clear();		

		activeGrid.breadthFirst();

		entity->think();

		//drawing of elements
		window->draw(backgroundS);		
		activeGrid.draw();
		window->draw(entity->GetSprite());

		window->display();
	}
	return 0;
}