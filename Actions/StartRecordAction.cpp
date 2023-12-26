#include "StartRecordAction.h"

StartRecordAction::StartRecordAction(ApplicationManager* pApp) :Action(pApp)
{
}

void StartRecordAction::ReadActionParameters()
{
	if (pManager->GetFigCount() == 0)
	{

		pManager->SetRecordingState(true);
		pManager->SetUndoRecordState(true);
		pOut->PrintMessage("Recording Started.");
		
		pManager->ClearRecord();
	}
	else
	{
		pOut->PrintMessage("ERROR: You can only record from a clear drawing area");
		//pManager->ExecuteAction(STOP_REC);
	}
}

void StartRecordAction::Execute()
{
	ReadActionParameters();

}

void StartRecordAction::undo()
{
}

void StartRecordAction::redo()
{
}
