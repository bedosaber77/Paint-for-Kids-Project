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

	}

	//Save this Action when Recording
	if (pManager->IsRecording())
		if (pManager->GetRecActCount() < pManager->GetMaxRecCount())
			pManager->RecordAction(this);


}
