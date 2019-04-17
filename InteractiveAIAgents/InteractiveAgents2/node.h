#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class node
{
public:
	node(sf::RectangleShape cellToRef);
	~node();

	enum nodeTypes
	{
		empty, //white
		start, //red
		path, //blue
		goal, //yellow
		checked, //pink
		obstacle, //black
	};

	nodeTypes nodeType;

	float posX;
	float posY;

	int rowVal;
	int colVal;

	int costToTraverse = 1;

	node* Parent = nullptr;
	node* Child = nullptr;

	node *north;
	node *south;
	node *west;
	node *east;

	std::vector<node*> neighbours;

	sf::RectangleShape cellRef;

	void update();
};

