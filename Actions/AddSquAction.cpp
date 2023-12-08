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
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(P1, SquGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(S);
}
