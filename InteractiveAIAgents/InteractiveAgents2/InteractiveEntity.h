#pragma once
#include <SFML/Graphics.hpp>

class StateMachine;
class node;
class grid;
class InteractiveEntity
{
public:
	InteractiveEntity(grid* grid);
	~InteractiveEntity();
	
	void think();
	StateMachine *fsm;

	sf::Vector2f velocity;
	float moveSpeed = 1;


	sf::Sprite entitySprite;
	sf::Texture texture;
	sf::Sprite GetSprite() { return entitySprite; }

	sf::Clock internalClock;

	int abituaryValue = 0;

	bool atTarget = false;
	node* targetNode;

	grid* currentGrid;

};

