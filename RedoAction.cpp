#include "RedoAction.h"

RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{
}
void RedoAction::ReadActionParameters()
{
}

void RedoAction::Execute()
{
	pManager->AddtoUndo();
	pManager->RedoIT();
	
}

void RedoAction::undo()
{
}

void RedoAction::redo()
{
}
