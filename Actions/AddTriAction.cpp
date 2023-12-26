#include "AddTriAction.h"
#include "CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//play Sound if on
	if (pManager->GetSoundStatues()) {
		PlaySound("Sounds\\triangle.wav", NULL, SND_ASYNC);
	}

	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	while (!pIn->GetPointForDrawing(P1.x, P1.y)) { // loop until a valid point is entered
		pOut->PrintMessage("Invalid Point Re-Choose Corner 1 Point");

	}

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	while (!pIn->GetPointForDrawing(P2.x, P2.y)) { // loop until a valid point is entered
		pOut->PrintMessage("Invalid Point Re-Choose Corner 2 Point");

	}

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	while (!pIn->GetPointForDrawing(P3.x, P3.y)) { // loop until a valid point is entered
		pOut->PrintMessage("Invalid Point Re-Choose Corner 3 Point");

	}

	TriGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()
{
	if (!pManager->IsPlayingRecord())
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	//Create a triangle with the parameters read from the user or Saved while Recording.
	T = new CTriangle(P1, P2, P3, TriGfxInfo);
	tmp = T;


	//Add the triangle to the list of figures
	pManager->AddFigure(T);
	pOut->PrintMessage("A Triangle has been succesfully Added");
	pManager->CreateInUndo(this);
}

void AddTriAction::undo()
{
	if (T != NULL) {
		tmp = T;
		pManager->RemoveFigure(T);
		T = NULL;
		pOut->PrintMessage("The Triangle has been successfully Undone");
	}
}

void AddTriAction::redo()
{
	T = tmp;
	pManager->AddFigure(T);
	tmp = NULL;
	pOut->PrintMessage("The Triangle has been successfully Redone");
}

AddTriAction::~AddTriAction()
{
	if (tmp != NULL)
		delete tmp;
}
