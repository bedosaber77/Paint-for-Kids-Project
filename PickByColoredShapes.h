#ifndef PICK_BY_COLORED_SHAPES_ACTION
#define PICK_BY_COLORED_SHAPES_ACTION

#include "Action.h"
#include "CFigure.h"
#include "../ApplicationManager.h"

class PickByColoredShapesAction :public Action
{
	Output* pOut;
public:
	PickByColoredShapesAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	virtual void redo();
};
#endif
