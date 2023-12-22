#include "ChangeColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeColorAction::ChangeColorAction(ApplicationManager* pApp , char c) : Action(pApp) ,  FillDraw(c) 
{}

void ChangeColorAction::ReadActionParameters()
{




}

void ChangeColorAction::Execute()
{
	FigurePt = pManager->GetSelectedFig();
	Output* pOut = pManager->GetOutput();
	if (FigurePt == NULL)
	{
		pOut->PrintMessage("No Figure Selected Please Select Figure ");
	}
	else {
		
		pOut->CreateColorToolBar();
		if (!pManager->IsPlayingRecord()) {
			LastDrawClr = FigurePt->getDrawClr();
			LastFillClr = FigurePt->getFillClr();
			wasFilled = FigurePt->IsFilled();

			ColorPick = pManager->GetUserAction();
	
			switch (ColorPick) {
			case  PICK_BLACK: { ColorPicked = BLACK;  } break;
			case  PICK_BLUE: { ColorPicked = BLUE;   } break;
			case  PICK_RED: { ColorPicked = RED;    } break;
			case  PICK_YELLOW: { ColorPicked = YELLOW; } break;
			case  PICK_GREEN: { ColorPicked = GREEN;  } break;
			case  PICK_ORANGE: { ColorPicked = ORANGE; } break;
			case  EMPTY: { ColorPicked = (FillDraw == 'F') ? UI.FillColor : UI.DrawColor; } break;
			}
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

	//Save this Action when Recording
	if (pManager->IsRecording())
		if (pManager->GetRecActCount() < pManager->GetMaxRecCount())
			pManager->RecordAction(this);
}
	
void ChangeColorAction::undo()
{
	if (FillDraw == 'F')
	{
		if (!wasFilled) {
			UI.FillColor = UI.BkGrndColor;
			FigurePt->ChngFillClr(UI.FillColor);
		}
		else {
			UI.FillColor = LastFillClr;
			FigurePt->ChngFillClr(UI.FillColor);
			UI.isFilled = true;
		}
	}

	else if (FillDraw == 'D')
	{
		UI.DrawColor = LastDrawClr;
		FigurePt->ChngDrawClr(UI.DrawColor);
	}
}

void ChangeColorAction::redo()
{
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
}
