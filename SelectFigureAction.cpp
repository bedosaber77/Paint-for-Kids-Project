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

	//This action needs to read some parameters first
	ReadActionParameters();

	CFigure* SelectedFig = pManager->GetFigure(SelectionPoint.x, SelectionPoint.y);
	if (SelectedFig != NULL && SelectedFig->IsSelected() == false )
	{
		SelectedFig->SetSelected(true);
		pManager->SetSelectedFig(SelectedFig);
		pOut->PrintMessage("Figure Selected");

	}
	else if (SelectedFig != NULL && SelectedFig->IsSelected() == true) {
	
		pOut->PrintMessage("Figure is Already Selected");	
	}	
	else if (SelectedFig == NULL)
		pOut->PrintMessage("No Figure Selected, Please Click On Figure");


}


