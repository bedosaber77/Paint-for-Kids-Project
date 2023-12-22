#include "AddCircAction.h"
#include "CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center Point");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at a Point On The Circle");

	//Read The Point On Circle and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	if (!pManager->IsPlayingRecord() || !pManager->IsRead())
	{
		//This action needs to read some parameters first
		ReadActionParameters();
		pManager->SettoRead();
	}

	//Create a circle with the parameters read from the user or Saved while Recording.
	C = new CCircle(P1, P2, CircGfxInfo);
	tmp = C;

	//Add the circle to the list of figures
	pManager->AddFigure(C);

	//Save this Action when Recording
	if (pManager->IsRecording())
		if (pManager->GetRecActCount() < pManager->GetMaxRecCount())
			pManager->RecordAction(this);
}

void AddCircAction::undo()
{
	if(C != NULL)
		pManager->RemoveFigure(C);
}

void AddCircAction::redo()
{
	C = tmp;
	pManager->AddFigure(C);
}

