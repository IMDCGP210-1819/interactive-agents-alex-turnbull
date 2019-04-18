#include "digState.h"



digState::digState(InteractiveEntity* newEntity)
{
	currentEntity = newEntity;
}


digState::~digState()
{
}

void digState::Enter()
{
	std::cout << "-- Entered Dig State --" << std::endl;
	currentEntity->clock.restart();
}

void digState::Run()
{
	sf::Time elapsed = currentEntity->clock.getElapsedTime();
	std::cout << "Running Dig State for: " << floorf(elapsed.asSeconds() * 100) / 100 << " seconds" << '\r';
}

void digState::Exit()
{
	std::cout << '\n' << "-- Left Dig State --" << std::endl << '\n';
}

BaseState * digState::GetNewState()
{
	sf::Time elapsed = currentEntity->clock.getElapsedTime();

	if (elapsed.asSeconds() > 5.0f)
	{
		return new bankState(currentEntity);
	}
	return nullptr;
}
