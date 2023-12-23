#include "PickByColoredShapes.h"

PickByColoredShapesAction::PickByColoredShapesAction(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
	pManager->PickRand();
}

void PickByColoredShapesAction::ReadActionParameters()
{
}

void PickByColoredShapesAction::Execute()
{
	pManager->PickByColoredShapes();
}

void PickByColoredShapesAction::undo()
{
}

void PickByColoredShapesAction::redo()
{
}
