#include "PickByShapeAction.h"

PickByShapeAction::PickByShapeAction(ApplicationManager* pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pManager->PickRand();
}

void PickByShapeAction::ReadActionParameters()
{
}

void PickByShapeAction::Execute()
{
	pManager->PickByShape();
}

void PickByShapeAction::undo()
{
}

void PickByShapeAction::redo()
{
}