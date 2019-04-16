#pragma once
#include <SFML/Graphics.hpp>

class node
{
public:
	node(sf::RectangleShape cellToRef);
	~node();

	enum nodeTypes
	{
		empty,
		start,
		path,
		goal,
		checked,
	};

	nodeTypes nodeType;

	int rowVal;
	int colVal;

	node *north;
	node *south;
	node *west;
	node *east;

	sf::RectangleShape cellRef;

	void update();
};

