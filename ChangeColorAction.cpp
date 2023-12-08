#include "ChangeColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeColorAction::ChangeColorAction(ApplicationManager* pApp , char c) : Action(pApp) ,  FillDraw(c) 
{




}

void ChangeColorAction::ReadActionParameters()
{




}

void ChangeColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* FigurePt = pManager->GetSelectedFig();
	if (FigurePt == NULL)
	{
		pOut->PrintMessage("No Figure Selected Please Select Figure "); pManager->redraw = 0;
	}
	else {
		pManager->redraw = 1;
		pOut->CreateColorToolBar();
		ActionType ColorPick = pManager->GetUserAction();
		color ColorPicked;
			switch (ColorPick) {
			case  PICK_BLACK:  { ColorPicked = BLACK;  } break;
			case  PICK_BLUE:   { ColorPicked = BLUE;   } break;
			case  PICK_RED:    { ColorPicked = RED;    } break;
			case  PICK_YELLOW: { ColorPicked = YELLOW; } break;
			case  PICK_GREEN:  { ColorPicked = GREEN;  } break;
			case  PICK_ORANGE: { ColorPicked = ORANGE; } break;
			case  EMPTY:       { ColorPicked = (FillDraw == 'F') ? UI.FillColor : UI.DrawColor; } break;
			}

			if (FillDraw == 'F')
			{
				UI.FillColor = ColorPicked;
				FigurePt->ChngFillClr(UI.FillColor);
				UI.isFilled = true;
			}

			else if (FillDraw == 'D')
			{
				UI.DrawColor = ColorPicked;
				FigurePt->ChngDrawClr(UI.DrawColor);
			}

			pOut->CreateDrawToolBar();

	}
}
	