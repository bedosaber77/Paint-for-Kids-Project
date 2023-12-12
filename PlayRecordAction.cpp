#include "PlayRecordAction.h"

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp):Action(pApp)
{
}

void PlayRecordAction::ReadActionParameters()
{
	if (pManager->GetRecActCount() == 0)
	{
		pOut->PrintMessage("No Record to display");
	}
	else
	{
	// do ClearAll
	pManager->SetPlayingRecordState(true);
	pManager->PlayRecord();
	}
}

void PlayRecordAction::Execute()
{
	ReadActionParameters();
}
