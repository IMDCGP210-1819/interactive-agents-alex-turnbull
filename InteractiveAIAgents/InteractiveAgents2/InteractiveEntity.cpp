#include "InteractiveEntity.h"
#include "StateMachine.h"

InteractiveEntity::InteractiveEntity(grid* grid)
{
	fsm = new StateMachine(this);

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
	fsm->Update();
}
