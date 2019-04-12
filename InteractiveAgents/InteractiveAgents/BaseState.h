#pragma once

class BaseState
{
public:
	virtual void Enter() = 0;
	virtual void d() = 0;
	virtual void Exit() = 0;

	virtual BaseState* GetNewState() = 0;
};

