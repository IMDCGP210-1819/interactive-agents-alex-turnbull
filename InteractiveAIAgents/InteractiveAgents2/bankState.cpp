#include "bankState.h"

bankState::bankState(InteractiveEntity* newEntity)
{
	currentEntity = newEntity;
}


bankState::~bankState()
{
}

void bankState::Enter()
{
	std::cout << "-- Entered Bank State --" << std::endl;
	currentEntity->clock.restart();
}

void bankState::Run()
{
	sf::Time elapsed = currentEntity->clock.getElapsedTime();
	std::cout << "Running Bank State for: " << floorf(elapsed.asSeconds() * 100) / 100 << " seconds" << '\r';
}

void bankState::Exit()
{
	std::cout << '\n' << "-- Left Bank State --" << std::endl << '\n';
}

BaseState * bankState::GetNewState()
{
	sf::Time elapsed = currentEntity->clock.getElapsedTime();

	if (elapsed.asSeconds() > 5.0f)
	{
		return new moveState(currentEntity);
	}
	return nullptr;
}
