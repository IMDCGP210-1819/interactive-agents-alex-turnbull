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
	case empty: cellRef.setFillColor(sf::Color::White);
		break;

	case start: cellRef.setFillColor(sf::Color::Red);
		break;

	case goal: cellRef.setFillColor(sf::Color::Yellow);
		break;

	case path: cellRef.setFillColor(sf::Color::Blue);
		break;

	case checked: cellRef.setFillColor(sf::Color::Magenta);
		break;

	case obstacle: cellRef.setFillColor(sf::Color::Black);
		break;

	default: cellRef.setFillColor(sf::Color::Green);
		break;
	}
}
