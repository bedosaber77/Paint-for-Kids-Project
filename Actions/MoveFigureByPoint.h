#pragma once
#include "Action.h"
#include "CFigure.h"

class MoveFigureByPoint :
	public Action
{
private:
	Point NewCenter;               //Current center 
	Point PrevCenter;       //Previous center 
	CFigure* SelectedFig;

public:

	MoveFigureByPoint(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void redo();
	void undo();




};
