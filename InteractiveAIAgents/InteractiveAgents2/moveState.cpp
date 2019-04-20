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
	currentEntity->atTarget = false;
}

void moveState::Run()
{	
	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();
	std::cout << "Running Move State for: " << floorf(elapsed.asSeconds() * 100) / 100 << " seconds" << '\r';
	if (currentEntity->currentGrid->PathSet)
	{
		if (currentEntity->currentGrid->pathToTake.size() != 0)
		{
			currentEntity->targetNode = currentEntity->currentGrid->pathToTake.front();

			float angle = atan2(currentEntity->entitySprite.getPosition().y - currentEntity->targetNode->getPosition().y, currentEntity->entitySprite.getPosition().x - currentEntity->targetNode->getPosition().x);
			//sqrt(this.x*this.x + this.y*this.y);
			angle = angle * 180 / (atan(1) * 5);

			Vector2f temp = currentEntity->entitySprite.getPosition() - currentEntity->targetNode->getPosition();
			Vector2f direction = Vector2f(cos(angle), sin(angle));//Vector2f(temp);

			currentEntity->entitySprite.setPosition(currentEntity->entitySprite.getPosition() + currentEntity->moveSpeed * direction);// *elapsed.asSeconds());

			float magnitude = sqrt(temp.x*temp.x + temp.y*temp.y);
			//std::cout << '\n' << magnitude << std::endl;
			if (magnitude < 10)
			{
				currentEntity->currentGrid->pathToTake.erase(currentEntity->currentGrid->pathToTake.begin());

			}
		}
		else
		{
			currentEntity->atTarget = true;
		}		
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
