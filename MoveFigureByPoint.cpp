#include "MoveFigureByPoint.h"
#include "ApplicationManager.h"

MoveFigureByPoint::MoveFigureByPoint(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;

}



void MoveFigureByPoint::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at Point Move the figure to ");
	pIn->GetPointClicked(NewCenter.x, NewCenter.y);
	pOut->ClearStatusBar();
}

void MoveFigureByPoint::Execute()
{

	Output* pOut = pManager->GetOutput();

	SelectedFig = pManager->GetSelectedFig();

	//Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("Select a Figure First");

	}
	else
	{
		ReadActionParameters();
		PrevCenter = SelectedFig->GetCenter(); // Use It For Recording And Undo
		SelectedFig->Moveto(NewCenter);

	}





}

void MoveFigureByPoint::undo()
{
}

void MoveFigureByPoint::redo()
{
}


