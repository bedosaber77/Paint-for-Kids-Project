#pragma once
#include "Action.h"
class ResizeAction :  public Action
{
private:
	Input* pIn;
	CFigure* SelectedFig;
	Point Cursor;
	Point prevPoint;
	Point newPoint;
	bool ReadOnce = 0;

public:

	ResizeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();



};

