#pragma once
#include "Action.h"
class ResizeAction :  public Action
{
private:
	Input* pIn;
	CFigure* SelectedFig;
	Point Cursor;


public:

	ResizeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();



};

