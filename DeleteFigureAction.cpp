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
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (Figure == NULL) pOut->PrintMessage("Please Select A Figure First");
	else
	{
		Figure->SetSelected(false);
		pManager->SetSelectedFig(NULL);
		pManager->RemoveFigure(Figure);

	}




}
