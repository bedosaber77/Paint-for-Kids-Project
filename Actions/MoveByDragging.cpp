#include "MoveByDragging.h"
#include "..\ApplicationManager.h"


MoveByDragging::MoveByDragging(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;

}



void MoveByDragging::ReadActionParameters()
{
	
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

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

	pOut = pManager->GetOutput(); // Should Actually be done in ReadActionParameters (Delete ya Ali :D)
	pIn = pManager->GetInput(); // Should Actually be done in ReadActionParameters (Delete ya Ali :D)
	ReadActionParameters();


	// Check If Selected Figure Is NULL
	if (SelectedFig != NULL)
	{
		PrevCenter = SelectedFig->GetCenter();
		do
		{
			pOut->PrintMessage("Moving");
			while (pIn->GetButtonStateLeftButton(Cursor) == BUTTON_DOWN) {
				// Update Position Of Selected Figure
				SelectedFig->Moveto(Cursor);
				pManager->UpdateInterface();
			}

			pOut->PrintMessage("Leave Figure To Finish, Click And Hold To Drag Figure");
			// Wait Until User Releases Mouse Button
			while (SelectedFig->IsInclude(Cursor) == 1 && pIn->GetButtonStateLeftButton(Cursor) != BUTTON_DOWN)
			{
			}


		} while (SelectedFig->IsInclude(Cursor) == 1);

		SelectedFig->PrintInfo(pOut); // Update Info On status Bar

	}
	NewCenter = SelectedFig->GetCenter();
	pManager->CreateInUndo(this);
}

void MoveByDragging::undo()
{
	SelectedFig->Moveto(PrevCenter);
	pOut->PrintMessage("Moving By Dragging Has Successfully Undone");
}

void MoveByDragging::redo()
{
	SelectedFig->Moveto(NewCenter);
	pOut->PrintMessage("Moving By Dragging Has Successfully Redone");
}


