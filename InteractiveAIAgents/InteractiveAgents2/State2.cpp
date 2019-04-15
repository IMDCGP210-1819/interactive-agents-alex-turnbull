#include "State2.h"



State2::State2(InteractiveEntity* newEntity)
{
	currentEntity = newEntity;
}


State2::~State2()
{
}

void State2::Enter()
{
	std::cout << " Entered State 2 " << std::endl;
}

void State2::Run()
{
	std::cout << "Running State 2" << std::endl;
}

void State2::Exit()
{
	std::cout << " Left State 2 " << std::endl;
}

BaseState * State2::GetNewState()
{
	return nullptr;
}
