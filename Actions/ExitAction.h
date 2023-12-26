#pragma once
#include "Action.h"


//Add Circle Action class
class ExitAction : public Action
{
public:
	ExitAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

	virtual void undo();
	virtual void redo();
};
