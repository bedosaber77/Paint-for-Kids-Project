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
	pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center Point");

	//Read Center and store in point P1

	while (!pIn->GetPointForDrawing(P1.x,P1.y) ){ // loop until a valid point is entered
		pOut->PrintMessage("Invalid Point Re-Choose Center Point");

	}

	pOut->PrintMessage("New Circle: Click at a Point On The Circle");
	
	//Read The Point On Circle and store in point P2
	while(!pIn->GetPointForDrawing(P2.x,P2.y)){ // loop until a valid point is entered
		pOut->PrintMessage("Invalid Point Re-Choose a Point On The Circle");
	}

	CircGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	
	//play Sound if on
	if (pManager->GetSoundStatues()) {
		PlaySound("Sounds\\circle.wav", NULL, SND_ASYNC);
	}


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
	pOut->PrintMessage("A Circle has been succesfully Added");
	pManager->CreateInUndo(this);
}

void AddCircAction::undo()
{
	//remove the circle from the list of figures
	if (C != NULL) {
		pManager->RemoveFigure(C);
		pOut->PrintMessage("The Circle has been successfully Undone");
	}
}

void AddCircAction::redo()
{
	//Add the circle to the list of figures
	C = tmp;
	pManager->AddFigure(C);
	pOut->PrintMessage("The Circle has been successfully Redone");
}

