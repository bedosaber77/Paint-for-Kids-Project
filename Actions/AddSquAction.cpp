#include "AddSquAction.h"
#include "CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquAction::AddSquAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center Point");

	//Read Center and store in point P1
	while (!pIn->GetPointForDrawing(P1.x, P1.y)) { // loop until a valid point is entered
		pOut->PrintMessage("Invalid Point Re-Choose Center Point");

	}

	SquGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquAction::Execute()
{
	//play Sound if on
	if (pManager->GetSoundStatues()) {
		PlaySound("Sounds\\square.wav", NULL, SND_ASYNC);
	}


	if (!pManager->IsPlayingRecord())
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	//Create a square with the parameters read from the user or Saved while Recording.
	S = new CSquare(P1, SquGfxInfo);
	tmp = S;

	//Add the square to the list of figures
	pManager->AddFigure(S);
	pOut->PrintMessage("A Square has been succesfully Added");
	pManager->CreateInUndo(this);
}

void AddSquAction::undo()
{
	if (S != NULL)
		tmp = S;
		pManager->RemoveFigure(S);
		S = NULL;
	pOut->PrintMessage("The Square has been successfully Undone");
}

void AddSquAction::redo()
{
	S = tmp;
	pManager->AddFigure(S);
	tmp = NULL;
	pOut->PrintMessage("The Square has been successfully Redone");
}

AddSquAction::~AddSquAction()
{
	if (tmp != NULL) {
		delete tmp;
		tmp = NULL;
	}
}
