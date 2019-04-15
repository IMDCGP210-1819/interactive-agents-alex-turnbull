#include "StateMachine.h"


StateMachine::StateMachine(InteractiveEntity *entity)
{
	interactiveEntity = entity;
	currentState = new State1(interactiveEntity);
}


StateMachine::~StateMachine()
{
}

void StateMachine::Update()
{
	currentState->Run();
	ChangeState(currentState->GetNewState());
}

void StateMachine::ChangeState(BaseState * newState)
{
	if (newState == nullptr) { return; }

	currentState->Exit();

	BaseState* oldState = currentState;
	currentState = newState;
	delete oldState; // deletes the previous current state in order to save memory.
}
