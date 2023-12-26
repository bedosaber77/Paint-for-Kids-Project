#include "ResizeAction.h"
#include "..\ApplicationManager.h"

ResizeAction::ResizeAction(ApplicationManager* pApp):Action(pApp)
{
}

void ResizeAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	SelectedFig = pManager->GetSelectedFig();
	if (!pManager->IsPlayingRecord()) {
		if (SelectedFig == NULL)
		{
			pOut->PrintMessage("Select A Figure First");
			return;
		}

		pOut->PrintMessage("Click on Corner of Selected Figure To Start Resizing");
		pIn->WaitMouseClick(Cursor);
		pOut->ClearStatusBar();
	}
}

void ResizeAction::Execute()
{
	ReadActionParameters();
	if (pManager->IsPlayingRecord())
		redo();
	else {
		if (SelectedFig == NULL)
		{
			pOut->PrintMessage("Select A Figure First");
			return;
		}
		else
			do
			{
				while (pIn->GetButtonStateLeftButton(Cursor) == BUTTON_DOWN)
				{
					if (!ReadOnce) {
						prevPoint = Cursor;
						ReadOnce = true;
					}

					if (Cursor.y >= UI.ToolBarHeight && Cursor.y < UI.height - UI.StatusBarHeight && Cursor.x >= 0 && Cursor.x <= UI.width) // Check If Cursor Is In Drawing Area
					{
						// Resize Figure
						SelectedFig->Resize(Cursor);
						pOut->PrintMessage("Resizing");

						pManager->UpdateInterface();
					}
					else pOut->PrintMessage("Out Of Bounds , Please Move Cursor To Drawing Area");

				}
				pOut->PrintMessage("Leave Corner To Finish, Click And Hold on Corner To Resize Figure");

			} while (SelectedFig->isOnCorner(Cursor));


			newPoint = Cursor;
			SelectedFig->PrintInfo(pOut);
	}
	pManager->CreateInUndo(this);
}

void ResizeAction::undo()
{
	SelectedFig->Resize(prevPoint);
	pOut->PrintMessage("Resizing Figure has been successfully Undo");
}

void ResizeAction::redo()
{
	SelectedFig->Resize(newPoint);
	pOut->PrintMessage("Resizing Figure has been successfully Redo");
}
