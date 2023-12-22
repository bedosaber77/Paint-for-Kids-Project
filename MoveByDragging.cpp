#include "MoveByDragging.h"
#include "ApplicationManager.h"


MoveByDragging::MoveByDragging(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;

}



void MoveByDragging::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	SelectedFig = pManager->GetSelectedFig();
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("Select A Figure First");
		return ;
	}

	pOut->PrintMessage("Click on Selected Figure To Start Moving By Dragging");
	pIn->WaitMouseClick(Cursor);
	pOut->ClearStatusBar();
}

void MoveByDragging::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();



	if (SelectedFig != NULL)
	{
		pOut->PrintMessage("Click And Hold To Drag Figure , Release Figure To Stop");
		do
		{
			pOut->PrintMessage("Moving");
			while (pIn->GetButtonStateLeftButton(Cursor) == BUTTON_DOWN) {
				SelectedFig->Moveto(Cursor);
				pManager->UpdateInterface();
			}

			pOut->PrintMessage("Leave Figure To Finish, Click And Hold To Drag Figure Again");

			while (SelectedFig->IsInclude(Cursor) == 1 && pIn->GetButtonStateLeftButton(Cursor) != BUTTON_DOWN)
			{
			}


		} while (SelectedFig->IsInclude(Cursor) == 1);

		pOut->PrintMessage("Figure Moved");

	}



}

void MoveByDragging::undo()
{

}

void MoveByDragging::redo()
{
}


