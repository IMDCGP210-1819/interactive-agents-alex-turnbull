#include "InteractiveEntity.h"
#include "StateMachine.h"

InteractiveEntity::InteractiveEntity()
{
	fsm = new StateMachine(this);

	std::string filename = "Assets\\pirateMan.png";
	texture.loadFromFile(filename);
	entitySprite.setOrigin(17, 17);
	entitySprite.setTexture(texture);
}


InteractiveEntity::~InteractiveEntity()
{
}

void InteractiveEntity::think()
{
	fsm->Update();
}
