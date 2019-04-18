#include "moveState.h"



moveState::moveState(InteractiveEntity* newEntity)
{
	currentEntity = newEntity;
}


moveState::~moveState()
{	
}

void moveState::Enter()
{
	std::cout << "-- Entered Move State --" << std::endl;
	currentEntity->clock.restart();
}

void moveState::Run()
{
	sf::Time elapsed = currentEntity->clock.getElapsedTime();
	std::cout << "Running Move State for: " << floorf(elapsed.asSeconds() * 100) / 100 << " seconds" << '\r';
}

void moveState::Exit()
{
	std::cout << '\n' << "-- Left Move State --" << std::endl << '\n';
}

BaseState * moveState::GetNewState()
{
	sf::Time elapsed = currentEntity->clock.getElapsedTime();

	if (elapsed.asSeconds() > 5.0f)
	{
		return new digState(currentEntity);
	}
	return nullptr;
}
