#include "MoveFigureByPoint.h"
#include "ApplicationManager.h"

MoveFigureByPoint::MoveFigureByPoint(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;

}



void MoveFigureByPoint::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at Point Move the figure to ");
	pIn->GetPointClicked(NewCenter.x, NewCenter.y);
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
		SelectedFig->Moveto(NewCenter);
		SelectedFig->PrintInfo(pOut); // Update Info On status Bar

	}


}

void MoveFigureByPoint::undo()
{
	SelectedFig->Moveto(PrevCenter);
	pOut->PrintMessage("The Moved figure has been successfully back to his previous position");
}

void MoveFigureByPoint::redo()
{
	SelectedFig->Moveto(NewCenter);
	pOut->PrintMessage("The Moved figure has been successfully back to his new position");
}


