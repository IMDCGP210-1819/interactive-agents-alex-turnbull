#include "InteractiveEntity.h"
#include "StateMachine.h"

InteractiveEntity::InteractiveEntity(grid* grid)
{
	//create a new State Machine instance to control the entity
	fsm = new StateMachine(this);

	//define variables for the entity
	std::string filename = "Assets\\pirateMan.png";
	texture.loadFromFile(filename);
	entitySprite.setOrigin(20, 20);
	entitySprite.setTexture(texture);

	currentGrid = grid;
}


InteractiveEntity::~InteractiveEntity()
{
}

void InteractiveEntity::think()
{
	//entity is controlled by the State Machine behind it
	//Update the State for visual output to screen
	switch (fsm->activeState)
	{
	case BaseState::Moving: 
		currentState = "Moving";
		break;

	case BaseState::Digging:
		currentState = "Digging";
		break;

	case BaseState::Banking:
		currentState = "Banking";
		break;
	}

	//run the State Machine
	fsm->Update();
}
