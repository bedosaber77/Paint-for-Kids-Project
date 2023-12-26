#include "UndoAction.h"

UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{
}

void UndoAction::ReadActionParameters()
{
}

void UndoAction::Execute()
{
	pManager->AddtoRedo();
	pManager->UndoIT();
}

void UndoAction::undo()
{
}

void UndoAction::redo()
{
}
