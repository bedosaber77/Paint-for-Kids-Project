#include "PickByShapeAction.h"

PickByShapeAction::PickByShapeAction(ApplicationManager* pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
}

void PickByShapeAction::ReadActionParameters()
{
	if (pManager->GetFigCount() != 0)
		pManager->PickRand();
	else
		pOut->PrintMessage("No Figures to start Play");
}


void PickByShapeAction::Execute()
{
	ReadActionParameters();

	if (pManager->GetFigCount() != 0)
		pManager->PickByShape();
}

void PickByShapeAction::undo()
{
}

void PickByShapeAction::redo()
{
}