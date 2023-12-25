#include "ExitAction.h"
#include "ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
}

void ExitAction::Execute()
{
	pManager->ClearRecord();
	pManager->SetUndoRecordState(false);
	pManager->ClearFigures();
	
}

void ExitAction::undo()
{
}

void ExitAction::redo()
{
}
