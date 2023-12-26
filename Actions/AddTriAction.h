#pragma once
#include "Action.h"
class AddTriAction :
    public Action
{

private:
	CFigure* T;
	CFigure* tmp;
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();

	virtual void undo();
	virtual void redo();
	~AddTriAction();
};

