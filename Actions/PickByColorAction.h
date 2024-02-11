#ifndef PICK_BY_COLOR_ACTION
#define PICK_BY_COLOR_ACTION

#include "Action.h"
#include "CFigure.h"
#include "../ApplicationManager.h"

class PickByColorAction :public Action
{
	Output* pOut;
	Input* pIn;
public:
	PickByColorAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	virtual void redo();
};
#endif