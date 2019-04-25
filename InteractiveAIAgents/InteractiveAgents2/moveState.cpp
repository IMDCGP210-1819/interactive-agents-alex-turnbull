#include "moveState.h"



moveState::moveState(InteractiveEntity* newEntity)
{
	currentEntity = newEntity;
	BaseState::activeState = States::Moving;
}


moveState::~moveState()
{	
}

void moveState::Enter()
{
	//define variables
	std::cout << "-- Entered Move State --" << std::endl;
	currentEntity->internalClock.restart();
	currentEntity->entitySprite.setColor(sf::Color::White);
	currentEntity->atTarget = false;
}

void moveState::Run()
{	
	//get delta time between frames for use with smooth movement
	sf::Time dt = DeltaClock.restart();

	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();
	std::cout << "Running Move State for: " << floorf(elapsed.asSeconds() * 100) / 100 << " seconds" << '\r';

	//can't move until the path has been calculated by the grid
	if (currentEntity->currentGrid->PathSet)
	{
		//whilst the list of nodes to follow is not empty follow it
		if (currentEntity->currentGrid->pathToTake.size() != 0)
		{
			//get the node front of the queue
			currentEntity->targetNode = currentEntity->currentGrid->pathToTake.front();

			//calculate the andle to move towards to reach the ndoe
			float angle = atan2(currentEntity->entitySprite.getPosition().y - currentEntity->targetNode->getPosition().y, currentEntity->entitySprite.getPosition().x - currentEntity->targetNode->getPosition().x);
			angle = angle * 180 / (atan(1) * 5);

			//calculate the directional vector for the magnitude and the actual direction to travel
			Vector2f temp = currentEntity->entitySprite.getPosition() - currentEntity->targetNode->getPosition();
			Vector2f direction = Vector2f(cos(angle), sin(angle));

			//update the position of the entity with smooth transition
			currentEntity->entitySprite.setPosition(currentEntity->entitySprite.getPosition() + currentEntity->moveSpeed * direction * dt.asSeconds());
			currentEntity->velocity = direction;

			float magnitude = sqrt(temp.x*temp.x + temp.y*temp.y);
			//std::cout << '\n' << magnitude << std::endl;
			if (magnitude < 10)
			{
				//once close enough to be assigned as reached the node, remove the current node from the queue so the next one can be traversed to
				currentEntity->currentGrid->pathToTake.erase(currentEntity->currentGrid->pathToTake.begin());

			}
		}
		else
		{
			//if the path is empty assume we have reached the target
			currentEntity->atTarget = true;
		}		
	}
}

void moveState::Exit()
{
	//debugging output to console
	std::cout << '\n' << "Reached Target";
	std::cout << '\n' << "-- Left Move State --" << std::endl << '\n';
}

BaseState * moveState::GetNewState()
{
	sf::Time elapsed = currentEntity->internalClock.getElapsedTime();

	//if at the target then move into the digging state
	if (currentEntity->atTarget)
	{
		return new digState(currentEntity);
	}

	//if plenty of treasure has been collected, "bank" it away
	if(currentEntity->treasureCount >= 5)
	{
		return new bankState(currentEntity);
	}
	return nullptr;
}
