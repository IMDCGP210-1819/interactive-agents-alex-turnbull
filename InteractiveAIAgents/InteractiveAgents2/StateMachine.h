#pragma once
#include "InteractiveEntity.h"
#include "BaseState.h"
//include States
#include "State1.h"
#include "State2.h"

class InteractiveEntity;
class BaseState;
class StateMachine
{
public:
	StateMachine(InteractiveEntity *entity);
	~StateMachine();

	void Update();

	void ChangeState(BaseState * newState);

	BaseState* currentState;
	InteractiveEntity* interactiveEntity;

};

