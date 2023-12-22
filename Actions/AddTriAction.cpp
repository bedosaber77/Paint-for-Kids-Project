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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()
{
	if (!pManager->IsPlayingRecord() || !pManager->IsRead())
	{
		//This action needs to read some parameters first
		ReadActionParameters();
		pManager->SettoRead();
	}

	//Create a triangle with the parameters read from the user or Saved while Recording.
	T = new CTriangle(P1, P2, P3, TriGfxInfo);
	tmp = T;


	//Add the triangle to the list of figures
	pManager->AddFigure(T);

	//Save this Action when Recording
	if (pManager->IsRecording())
		if (pManager->GetRecActCount() < pManager->GetMaxRecCount())
			pManager->RecordAction(this);
}

void AddTriAction::undo()
{
	if (T != NULL)
		pManager->RemoveFigure(T);
}

void AddTriAction::redo()
{
	T = tmp;
	pManager->AddFigure(T);
}
