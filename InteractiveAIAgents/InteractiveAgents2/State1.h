#pragma once
#include "BaseState.h"
#include "State2.h"
#include "InteractiveEntity.h"

class State1 :
	public BaseState
{
public:
	State1(InteractiveEntity* newEntity);
	~State1();

	void Enter();
	void Run();
	void Exit();

	BaseState* GetNewState();

	InteractiveEntity* currentEntity;

};

