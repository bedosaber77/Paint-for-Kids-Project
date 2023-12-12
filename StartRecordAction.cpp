#include "StartRecordAction.h"

StartRecordAction::StartRecordAction(ApplicationManager* pApp) :Action(pApp)
{
}

void StartRecordAction::ReadActionParameters()
{
	if (pManager->GetFigCount() == 0)
	{

		pManager->SetRecordingState(true);

		pOut->PrintMessage("Recording Started.");
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
	pManager->ClearRecord();
}