#include "PlayRecordAction.h"

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp):Action(pApp)
{
}

void PlayRecordAction::ReadActionParameters()
{
	if (pManager->GetRecActCount() == 0)
	{
		pOut->PrintMessage("No Record to display.");
	}
	else
	{
	if (!pManager->IsRecording()){
		//Clear First
		pOut->ClearDrawArea();
		pManager->ClearFigures();
		//to not re reading paramaters
		pManager->SetPlayingRecordState(true);
		pManager->PlayRecord();
		pManager->SetPlayingRecordState(false);
		//to prevent undo And redo stacks from deleting
		pManager->SetUndoRecordState(false);
		pOut->PrintMessage("Playing Record has ended.");
	}
	else
		pOut->PrintMessage("Stop Record First");

	}
}

void PlayRecordAction::Execute()
{
	ReadActionParameters();
}

void PlayRecordAction::undo()
{
}

void PlayRecordAction::redo()
{
}