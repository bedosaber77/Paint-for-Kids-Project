#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
}
//No Parameters for this action
void ClearAllAction::ReadActionParameters()
{
}
//calling a function implemented to clear what the user drawn
void ClearAllAction::Execute()
{
	pManager->ClearFigures();
	if (pManager->IsRecording()) {
		pManager->ExecuteAction(STOP_REC);
	}
		pManager->ClearRecord();
	
	//pManager->SetUndoRecordState(false);
	pOut->PrintMessage("All cleared, Back to initial state");
}

void ClearAllAction::undo()
{
}

void ClearAllAction::redo()
{
}