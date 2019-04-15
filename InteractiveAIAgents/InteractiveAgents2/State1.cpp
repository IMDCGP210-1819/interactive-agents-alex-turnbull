#include "State1.h"



State1::State1(InteractiveEntity* newEntity)
{
	currentEntity = newEntity;
}


State1::~State1()
{	
}

void State1::Enter()
{
	std::cout << " Entered State 1 " << std::endl;
}

void State1::Run()
{
	std::cout << "Running State 1" << std::endl;
}

void State1::Exit()
{
	std::cout << " Left State 1 " << std::endl;
}

BaseState * State1::GetNewState()
{
	return nullptr;
}
