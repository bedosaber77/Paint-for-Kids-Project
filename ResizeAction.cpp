#include "ResizeAction.h"
#include "ApplicationManager.h"

ResizeAction::ResizeAction(ApplicationManager* pApp):Action(pApp)
{
}

void ResizeAction::ReadActionParameters()
{
	SelectedFig = pManager->GetSelectedFig();
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("Select A Figure First");
		return;
	}

	pOut->PrintMessage("Click on Selected Figure To Start Resizing");
	pIn->WaitMouseClick(Cursor);
	pOut->ClearStatusBar();
}

void ResizeAction::Execute()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	ReadActionParameters();
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("Select A Figure First");
		return;
	}
	else
	do
	{
		pOut->PrintMessage("Click And Hold To Resizing");
		while (pIn->GetButtonStateLeftButton(Cursor)==BUTTON_DOWN)
		{
			if (!ReadOnce) {
				prevPoint = Cursor;
				ReadOnce = true;
			}
			SelectedFig->Resize(Cursor);
			pManager->UpdateInterface();
		}
		pOut->PrintMessage("Leave Figure To Finish, Click And Hold To Drag Figure Again");

		while (SelectedFig->isOnCorner(Cursor) == 1 && pIn->GetButtonStateLeftButton(Cursor) != BUTTON_DOWN)
		{
		}
	} while (SelectedFig->isOnCorner(Cursor));
	newPoint = Cursor;
	SelectedFig->PrintInfo(pOut);
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
