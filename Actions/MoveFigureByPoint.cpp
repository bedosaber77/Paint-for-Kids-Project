#include "MoveFigureByPoint.h"
#include "..\ApplicationManager.h"

MoveFigureByPoint::MoveFigureByPoint(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;

}



void MoveFigureByPoint::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	//Print Action Message
	pOut->PrintMessage("Click at Point Move the figure to ");

	while (!pIn->GetPointForDrawing(NewCenter.x, NewCenter.y)) { // loop until a valid point is entered
		pOut->PrintMessage("Invalid Point Re-Choose Point to move");

	}
	pOut->ClearStatusBar();
}

void MoveFigureByPoint::Execute()
{

	pOut = pManager->GetOutput();

	SelectedFig = pManager->GetSelectedFig();

	//Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("Select a Figure First");

	}
	else
	{
		if(!pManager->IsPlayingRecord())
		{
			ReadActionParameters();
		}
		PrevCenter = SelectedFig->GetCenter(); // Use It For Recording And Undo
		SelectedFig->Moveto(NewCenter); // Move The Figure To The New Center
		SelectedFig->PrintInfo(pOut); // Update Info On status Bar

	}

	pManager->CreateInUndo(this);
}

void MoveFigureByPoint::undo()
{
	SelectedFig->Moveto(PrevCenter);
	pOut->PrintMessage("The Moved figure has been successfully back to his Previous position");
}

void MoveFigureByPoint::redo()
{
	SelectedFig->Moveto(NewCenter);
	pOut->PrintMessage("The Moved figure has been successfully back to his New position");
}


