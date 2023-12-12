#include "StopRecordAction.h"

StopRecordAction::StopRecordAction(ApplicationManager* pApp) :Action(pApp)
{
}

void StopRecordAction::ReadActionParameters()
{
	if (pManager->IsRecording())
	{
		pManager->SetRecordingState(false);
		pOut->PrintMessage("Recording Ended.");
	}
	else
		pOut->PrintMessage("You are not Recording.");
}

void StopRecordAction::Execute()
{
	ReadActionParameters();
}
