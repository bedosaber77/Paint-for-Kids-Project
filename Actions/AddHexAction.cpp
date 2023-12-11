#include "AddHexAction.h"
#include "CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center Point");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	HexGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	if (!pManager->IsPlayingRecord())
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	//Create a hexagon with the parameters read from the user or Saved while Recording.
	CHexagon* H = new CHexagon(P1, HexGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);

	//Save this Action when Recording
	if (pManager->IsRecording())
		if (pManager->GetRecActCount() < pManager->GetMaxRecCount())
			pManager->RecordAction(this);
}
