#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
}
//No Parameters for this action
void ClearAllAction::ReadActionParameters()
{
}
//calling a function implemented to clear what the user drawn
//Not finished yet
//to be continued after finishing {Recording}
void ClearAllAction::Execute()
{
	pManager->ClearFigures();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("All cleared, Back to initial state");
}

void ClearAllAction::undo()
{
}

void ClearAllAction::redo()
{
}