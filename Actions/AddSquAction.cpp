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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center Point");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

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
	CSquare* S = new CSquare(P1, SquGfxInfo);
	

	//Add the square to the list of figures
	pManager->AddFigure(S);

	//Save this Action when Recording
	if (pManager->IsRecording())
		if (pManager->GetRecActCount() < pManager->GetMaxRecCount())
			pManager->RecordAction(this);
}
