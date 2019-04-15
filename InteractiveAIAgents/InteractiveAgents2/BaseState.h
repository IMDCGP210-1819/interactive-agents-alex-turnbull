#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "InteractiveEntity.h"

class BaseState
{
public:
	virtual void Enter() = 0;
	virtual void Run() = 0;
	virtual void Exit() = 0;

	virtual BaseState* GetNewState() = 0;
};