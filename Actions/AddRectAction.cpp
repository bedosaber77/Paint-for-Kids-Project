#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//play Sound if on
	if (pManager->GetSoundStatues()) {
		PlaySound("Sounds\\rectangle.wav", NULL, SND_ASYNC);
	}


	if (!pManager->IsPlayingRecord() || !pManager->IsRead())
	{
		//This action needs to read some parameters first
		ReadActionParameters();
		pManager->SettoRead();
	}

	//Create a rectangle with the parameters read from the user or Saved while Recording.
	R = new CRectangle(P1, P2, RectGfxInfo);
	tmp = R;

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	pOut->PrintMessage("A Rectangle has been succesfully Added");
	pManager->CreateInUndo(this);

}

void AddRectAction::undo()
{
	if (R != NULL) {
		pManager->RemoveFigure(R);
		pOut->PrintMessage("The Rectangle has been successfully Undone");
	}
}

void AddRectAction::redo()
{
	R = tmp;
	pManager->AddFigure(R);
	pOut->PrintMessage("The Rectangle has been successfully Redone");
}

