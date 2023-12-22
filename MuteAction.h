#pragma once
#include "Action.h"
class MuteAction : public Action
{
public:
	MuteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

