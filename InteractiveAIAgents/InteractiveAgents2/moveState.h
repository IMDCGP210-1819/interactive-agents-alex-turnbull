#pragma once
#include "BaseState.h"
#include "digState.h"
#include "bankState.h"
#include "InteractiveEntity.h"

class moveState :
	public BaseState
{
public:
	moveState(InteractiveEntity* newEntity);
	~moveState();

	void Enter();
	void Run();
	void Exit();

	BaseState* GetNewState();

	InteractiveEntity* currentEntity;

};

