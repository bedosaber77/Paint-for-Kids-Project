#ifndef PICK_BY_SHAPE_ACTION
#define PICK_BY_SHAPE_ACTION

#include "Action.h"
#include "CFigure.h"
#include "../ApplicationManager.h"

class PickByShapeAction :public Action
{
	Output* pOut;
	Input* pIn;
public:
	PickByShapeAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	virtual void redo();
};
#endif