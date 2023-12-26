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
			return;
		}

		pOut->PrintMessage("Click on Selected Figure To Start Moving By Dragging");
		pIn->WaitMouseClick(Cursor);

	pOut->ClearStatusBar();
}

void MoveByDragging::Execute()
{

	if (pManager->IsPlayingRecord())
	{
		SelectedFig = pManager->GetSelectedFig(); // Get Selected Fig
		redo();
	}



	else {

		ReadActionParameters();

		// Check If Selected Figure Is NULL
		if (SelectedFig != NULL)
		{
			PrevCenter = SelectedFig->GetCenter();
			do
			{
				while (pIn->GetButtonStateLeftButton(Cursor) == BUTTON_DOWN)
				{

					if (Cursor.y >= UI.ToolBarHeight && Cursor.y < UI.height - UI.StatusBarHeight && Cursor.x >= 0 && Cursor.x <= UI.width) // Check If Cursor Is In Drawing Area
					{
						// Update Position Of Selected Figure
						SelectedFig->Moveto(Cursor);
						pOut->PrintMessage("Moving");

						pManager->UpdateInterface();
					}
					else pOut->PrintMessage("Out Of Bounds , Please Move Cursor To Drawing Area");
				}

				pOut->PrintMessage("Leave Figure To Finish, Click And Hold To Drag Figure");

			} while (SelectedFig->IsInclude(Cursor) == 1);

			SelectedFig->PrintInfo(pOut); // Update Info On status Bar
			NewCenter = SelectedFig->GetCenter();
			pManager->CreateInUndo(this);

		}

	}
}

void MoveByDragging::undo()
{
	SelectedFig->Moveto(PrevCenter);
	pOut->PrintMessage("Moving By Dragging Has Successfully Undone");
}

void MoveByDragging::redo()
{
	if (SelectedFig != NULL)
	{
		SelectedFig->Moveto(NewCenter);
		pOut->PrintMessage("Moving By Dragging Has Successfully Redone");

	}
}

