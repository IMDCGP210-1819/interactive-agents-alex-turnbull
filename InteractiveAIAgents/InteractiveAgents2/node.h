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

	float posX;
	float posY;

	sf::RectangleShape cellRef;

	void update();
};

