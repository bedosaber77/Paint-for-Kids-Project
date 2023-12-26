#include "PickByColoredShapes.h"

PickByColoredShapesAction::PickByColoredShapesAction(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
}

void PickByColoredShapesAction::ReadActionParameters()
{
	if (pManager->GetFigCount() != 0)
		pManager->PickRand();
	else
		pOut->PrintMessage("No Figures to start Play");
}

void PickByColoredShapesAction::Execute()
{
	ReadActionParameters();

	if (pManager->GetFigCount() != 0)
		pManager->PickByColoredShapes();
}

void PickByColoredShapesAction::undo()
{
}

void PickByColoredShapesAction::redo()
{
}
