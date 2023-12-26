#include "PickByColorAction.h"

PickByColorAction::PickByColorAction(ApplicationManager* pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void PickByColorAction::ReadActionParameters()
{
}

void PickByColorAction::Execute()
{
	if (pManager->GetFigCount() != 0)
	{
		pManager->RestartGame();
		pManager->PickRand();
		pManager->SetGameMode(true);

		Restart:
		pOut->PrintMessage("Pick all " + pOut->ColorString(pManager->GetPickingColor()) + " filled Shapes.");
	
		ActionType Act = EMPTY;

		bool cont = 1;
		bool Switch = 0;

		while (cont)
		{
			Point PickPoint;
			pIn->GetPointClicked(PickPoint.x, PickPoint.y);
			CFigure* PickedFig = pManager->GetFigure(PickPoint.x, PickPoint.y);

			if (PickedFig != NULL)
			{
				if (!PickedFig->GetHidden())
					if (pManager->GetPickingFig()->GetColor() == PickedFig->GetColor()) pManager->IncrementCorrectPicks();
					else pManager->IncrementWrongPicks();
				PickedFig->SetHidden(1);
			}
			else
			{
				Act = pIn->GetUserAction(PickPoint.x, PickPoint.y, pManager->GetGameMode());

				switch (Act)
				{
				case RESTART_PLAY:
					pManager->ExecuteAction(Act);
					pOut->PrintMessage("Game Restarted.");
					Sleep(1000);
					goto Restart;
					break;

				case SHAPE_PLAY_PICK:
				case COLOR_PLAY_PICK:
				case COLORED_SHAPE_PLAY_PICK:
					Switch = 1;
					goto SWITCHMODE;
					break;

				case DRAWING_AREA:
					break;
				}
			}

			if (pManager->GetCorrectPicks() == pManager->GetPickingColorCount())
			{
				pOut->PrintMessage("Final Score: " + to_string(pManager->GetCorrectPicks()) + " correct picks, " + to_string(pManager->GetWrongPicks()) + " wrong picks.");
				cont = 0;
				pManager->RestartGame();
			}

			pManager->UpdateInterface();

		}

		pManager->SetGameMode(false);

		SWITCHMODE:
		if (Switch)
		{
			pOut->PrintMessage("Switching Mode.");
			Sleep(1000);
			pManager->ExecuteAction(Act);
		}
	}
	else
		pOut->PrintMessage("No Figures to start Play");
}

void PickByColorAction::undo()
{
}

void PickByColorAction::redo()
{
}