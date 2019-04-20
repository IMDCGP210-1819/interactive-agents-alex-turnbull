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
	currentEntity->internalClock.restart();
	currentEntity->entitySprite.setColor(sf::Color::Red);
}

void moveState::Run()
{	
	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();
	std::cout << "Running Move State for: " << floorf(elapsed.asSeconds() * 100) / 100 << " seconds" << '\r';
	if (currentEntity->currentGrid->PathSet)
	{
		currentEntity->targetNode = currentEntity->currentGrid->pathToTake[0];
	}
}

void moveState::Exit()
{
	std::cout << '\n' << "-- Left Move State --" << std::endl << '\n';
}

BaseState * moveState::GetNewState()
{
	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();

	if (currentEntity->atTarget)
	{
		return new digState(currentEntity);
	}

	if(currentEntity->abituaryValue >= 5)
	{
		return new bankState(currentEntity);
	}
	return nullptr;
}
