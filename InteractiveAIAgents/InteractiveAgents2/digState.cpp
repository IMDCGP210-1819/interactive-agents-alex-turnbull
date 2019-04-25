#include "digState.h"



digState::digState(InteractiveEntity* newEntity)
{
	currentEntity = newEntity;
	BaseState::activeState = States::Digging;
}


digState::~digState()
{
}

void digState::Enter()
{
	//debugging variables and initlisation
	std::cout << "-- Entered Dig State --" << std::endl;
	currentEntity->internalClock.restart();
	currentEntity->entitySprite.setColor(sf::Color(73, 30, 0));
}

void digState::Run()
{
	//basic state that gets handled for a defined time
	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();
	std::cout << "Running Dig State for: " << floorf(elapsed.asSeconds() * 100) / 100 << " seconds" << '\r';
}

void digState::Exit()
{
	//debugging output to console
	std::cout << '\n' << "Successfully collected treasure";
	std::cout << '\n' << "-- Left Dig State --" << std::endl << '\n';
}

BaseState * digState::GetNewState()
{
	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();

	//changes state after being run for 2 seconds
	//simulation of priate digging for treasure
	//animation etc could be included
	if (elapsed.asSeconds() > 2.0f)
	{
		//reset values and the grid ready for next pathfinding search
		currentEntity->treasureCount += 1;
		currentEntity->currentGrid->resetValues();

		//move into the Move State
		return new moveState(currentEntity);
	}
	return nullptr;
}
