#include "PickByColorAction.h"

PickByColorAction::PickByColorAction(ApplicationManager* pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pManager->PickRand();
}

void PickByColorAction::ReadActionParameters()
{
}

void PickByColorAction::Execute()
{
	pManager->PickByColor();
}

void PickByColorAction::undo()
{
}

void PickByColorAction::redo()
{
}
