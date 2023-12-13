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
	// do ClearAll
	pManager->SetPlayingRecordState(true);
	pManager->PlayRecord();
	pManager->SetPlayingRecordState(false);
	pOut->PrintMessage("Palying Record has ended.");
	}
}

void PlayRecordAction::Execute()
{
	ReadActionParameters();
}
