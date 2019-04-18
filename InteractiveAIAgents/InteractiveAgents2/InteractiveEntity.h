#pragma once
#include <SFML/Graphics.hpp>

class StateMachine;
class InteractiveEntity
{
public:
	InteractiveEntity();
	~InteractiveEntity();
	
	void think();
	StateMachine *fsm;

	sf::Sprite entitySprite;
	sf::Texture texture;
	sf::Sprite GetSprite() { return entitySprite; }

	sf::Clock internalClock;

	int abituaryValue = 0;

	bool atTarget = false;

};

