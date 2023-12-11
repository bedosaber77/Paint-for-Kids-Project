#include "RecordAction.h"

RecordAction::RecordAction(ApplicationManager* pApp) :Action(pApp)
{
}

void RecordAction::ReadActionParameters()
{
	if (pManager->GetFigCount() == 0)
	{

		pManager->SetRecordingState(true);

		pOut->PrintMessage("Recording Started.");
	}
	else
	{
		pOut->PrintMessage("You can only record from a clear drawing area");
		pManager->ExecuteAction(STOP_REC);
	}
}

void RecordAction::Execute()
{
	ReadActionParameters();
	pManager->ClearRecord();
}