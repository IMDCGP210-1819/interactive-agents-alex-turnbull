#pragma once
#include "BaseState.h"
#include "State1.h"

class InteractiveEntity;
class State2 :
	public BaseState
{
public:
	State2(InteractiveEntity* newEntity);
	~State2();

	void Enter();
	void Run();
	void Exit();

	BaseState* GetNewState();

	InteractiveEntity* currentEntity;

};

