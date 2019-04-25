#include "StateMachine.h"


StateMachine::StateMachine(InteractiveEntity *entity)
{
	//take in the entity to control and give it an initial state
	interactiveEntity = entity;
	currentState = new moveState(interactiveEntity);
	currentState->Enter();
}


StateMachine::~StateMachine()
{
}

void StateMachine::Update()
{
	//update the state machine by running the Run and Change State functions of the current state
	activeState = currentState->activeState;
	currentState->Run();
	ChangeState(currentState->GetNewState());
}

void StateMachine::ChangeState(BaseState * newState)
{
	//if the state provided is invalid then just return and continue running the current state
	if (newState == nullptr)
	{ 
		return;
	}

	//on state change call the exit function 
	currentState->Exit();

	//define the new state and call its entry function
	BaseState* previousState = currentState;
	currentState = newState;
	currentState->Enter();

	//delete the previous state to clean up memory
	delete previousState;
}
