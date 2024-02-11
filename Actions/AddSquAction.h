#pragma once
#include "Action.h"

class AddSquAction : public Action
{
private:
	CFigure* S;
	CFigure* tmp;
	Point P1; //Center Point
	GfxInfo SquGfxInfo;
public:
	AddSquAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();

	virtual void undo();
	virtual void redo();
	~AddSquAction();
};

