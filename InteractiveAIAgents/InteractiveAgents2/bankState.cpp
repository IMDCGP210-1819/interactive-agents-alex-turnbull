#include "bankState.h"

bankState::bankState(InteractiveEntity* newEntity)
{
	currentEntity = newEntity;
	BaseState::activeState = States::Banking;
}


bankState::~bankState()
{
}

void bankState::Enter()
{
	//debugging variables and initlisation
	std::cout << "-- Entered Bank State --" << std::endl;
	currentEntity->internalClock.restart();
	currentEntity->entitySprite.setColor(sf::Color::Yellow);
}

void bankState::Run()
{
	//basic state that gets handled for a defined time
	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();
	std::cout << "Running Bank State for: " << floorf(elapsed.asSeconds() * 100) / 100 << " seconds" << '\r';
}

void bankState::Exit()
{
	//debugging output to console
	std::cout << '\n' << "Successfully banked all treasure in hand";
	std::cout << '\n' << "-- Left Bank State --" << std::endl << '\n';
}

BaseState * bankState::GetNewState()
{
	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();

	//state changes after 3 seconds of runtime has elapsed
	//simulating the pirate putting treasure away
	if (elapsed.asSeconds() > 3.0f)
	{
		//reset variable and transition into new state
		currentEntity->treasureCount = 0;
		return new moveState(currentEntity);
	}
	return nullptr;
}
