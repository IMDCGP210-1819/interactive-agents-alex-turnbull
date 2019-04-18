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

	sf::Clock clock;

};

