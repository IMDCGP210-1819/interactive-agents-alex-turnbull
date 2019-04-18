#include "InteractiveEntity.h"
#include "StateMachine.h"

InteractiveEntity::InteractiveEntity()
{
	fsm = new StateMachine(this);
}


InteractiveEntity::~InteractiveEntity()
{
}

void InteractiveEntity::think()
{
	fsm->Update();
}
