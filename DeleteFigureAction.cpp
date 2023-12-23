#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) : Action(pApp)
{




}

void DeleteFigureAction::ReadActionParameters()
{
	Figure = pManager->GetSelectedFig();
	Backup = Figure;
}

void DeleteFigureAction::Execute()
{
		//This action needs to read some parameters first
		ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	if (Figure == NULL) pOut->PrintMessage("Please Select A Figure First");
	else
	{
		Figure->SetSelected(false);
		pManager->SetSelectedFig(NULL);
		pManager->RemoveFigure(Figure);
		Figure = NULL;

	}

	//Save this Action when Recording
	if (pManager->IsRecording())
		if (pManager->GetRecActCount() < pManager->GetMaxRecCount())
			pManager->RecordAction(this);


}

void DeleteFigureAction::undo()
{
	Output* pOut = pManager->GetOutput();
	if (Figure == NULL) {
		Figure = Backup;
		pManager->AddFigure(Figure);
		Backup = NULL;
		pOut->PrintMessage("Deletion of the Fig has been successfully Undone");
	}
}

void DeleteFigureAction::redo()
{
	Output* pOut = pManager->GetOutput();
	if (Backup == NULL){ 
		pManager->RemoveFigure(Figure);
		Backup = Figure;
		Figure = NULL;
		pOut->PrintMessage("Deletion of the Fig has been successfully Undone");
	}
}
