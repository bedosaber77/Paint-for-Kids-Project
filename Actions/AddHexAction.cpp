#include "AddHexAction.h"
#include "CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{
 
}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center Point");

	//Read Center and store in point P1
	while (!pIn->GetPointForDrawing(P1.x, P1.y)) { // loop until a valid point is entered
		pOut->PrintMessage("Invalid Point Re-Choose Center Point");

	}

	HexGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	//play Sound if on
	if (pManager->GetSoundStatues()) {
		PlaySound("Sounds\\hexagon.wav", NULL, SND_ASYNC);
	}

	if (!pManager->IsPlayingRecord() || !pManager->IsRead())
	{
		//This action needs to read some parameters first
		ReadActionParameters();
		pManager->SettoRead();
	}

	//Create a hexagon with the parameters read from the user or Saved while Recording.
	H = new CHexagon(P1, HexGfxInfo);
	tmp = H;

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
	pOut->PrintMessage("A Hexagon has been succesfully Added");
	pManager->CreateInUndo(this);
}

void AddHexAction::undo()
{
	if (H != NULL) {
		pManager->RemoveFigure(H);
		pOut->PrintMessage("The Hexagon has been successfully Undone");
	}
}

void AddHexAction::redo()
{

	H = tmp;
	pManager->AddFigure(H);
	pOut->PrintMessage("The Hexagon has been successfully Redone");
}
