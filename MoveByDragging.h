#pragma once
#include "Action.h"
#include "CFigure.h"

class MoveByDragging :
	public Action
{
private:
	Point NewCenter;               //Current center 
	Point PrevCenter;			    //Previous center 
	CFigure* SelectedFig;
	Point Cursor;


public:

	MoveByDragging(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();



};

