#include "SelectFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectFigureAction::SelectFigureAction(ApplicationManager* pApp) : Action(pApp)
{



}

void SelectFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	// Get Point 
	pOut->PrintMessage("Select A Figure ->");
	pIn->GetPointClicked(SelectionPoint.x, SelectionPoint.y);

}

void SelectFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	//play Sound if on
	if (pManager->GetSoundStatues()) {
		PlaySound("Sounds\\select.wav", NULL, SND_ASYNC);
	}


	if (!pManager->IsPlayingRecord())
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	CFigure* SelectedFig = pManager->GetFigure(SelectionPoint.x, SelectionPoint.y);
	pManager->SelectFigure(SelectedFig);
	if (SelectedFig != NULL && SelectedFig->IsSelected() == false)
	{
		SelectedFig->SetSelected(true);
		pManager->SetSelectedFig(SelectedFig);
		SelectedFig->PrintInfo(pOut);

	}
	else if (SelectedFig != NULL && SelectedFig->IsSelected() == true) {
		SelectedFig->SetSelected(false);
		SelectedFig = NULL;
		pManager->SetSelectedFig(SelectedFig);
		pOut->PrintMessage("Figure is Deselected");	
	}	
	else if (SelectedFig == NULL)
		pOut->PrintMessage("No Figure Selected, Please Click On Figure");

	//Save this Action when Recording
	if (pManager->IsRecording())
		if (pManager->GetRecActCount() < pManager->GetMaxRecCount())
			pManager->RecordAction(this);

}


