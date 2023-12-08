#pragma once
#include "Action.h"

class AddSquAction : public Action
{
private:
	Point P1; //Center Point
	GfxInfo SquGfxInfo;
public:
	AddSquAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();

};

