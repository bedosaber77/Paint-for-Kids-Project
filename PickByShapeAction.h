#ifndef PICK_BY_SHAPE_ACTION
#define PICK_BY_SHAPE_ACTION
#include "Action.h"
#include "CFigure.h"
#include "../ApplicationManager.h"
class PickByShapeAction:public Action
{
	CFigure* PickedFig; //Constr.
	
public:
	PickByShapeAction(ApplicationManager*);
	void ReadActionParameters();
	void Execute();

};

#endif

