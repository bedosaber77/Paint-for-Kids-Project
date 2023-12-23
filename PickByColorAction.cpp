#include "PickByColorAction.h"

PickByColorAction::PickByColorAction(ApplicationManager* pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
}

void PickByColorAction::ReadActionParameters()
{
	if (pManager->GetFigCount() != 0)
		pManager->PickRand();
	else
		pOut->PrintMessage("No Figures to start Play");
}

void PickByColorAction::Execute()
{
	ReadActionParameters();

	if (pManager->GetFigCount() != 0)
		pManager->PickByColor();
}

void PickByColorAction::undo()
{
}

void PickByColorAction::redo()
{
}
