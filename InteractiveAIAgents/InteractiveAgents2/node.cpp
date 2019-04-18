#include "node.h"



node::node(sf::RectangleShape cellToRef)
{
	nodeType = empty;
	cellRef = cellToRef;
}


node::~node()
{
}

void node::update()
{
	switch(nodeType)
	{
	case empty: cellRef.setFillColor(sf::Color(255,255,255,75));
		break;

	case start: cellRef.setFillColor(sf::Color(255, 0, 0, 75));
		break;

	case goal: cellRef.setFillColor(sf::Color(0, 255, 255, 75));
		break;

	case path: cellRef.setFillColor(sf::Color(0, 0, 255, 75));
		break;

	case checked: cellRef.setFillColor(sf::Color(110, 0, 114, 75));
		break;

	case obstacle: cellRef.setFillColor(sf::Color(0, 0, 0, 75));
		break;

	default: cellRef.setFillColor(sf::Color::Green);
		break;
	}
}
