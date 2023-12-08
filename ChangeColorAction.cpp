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
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	CFigure* FigurePt = pManager->GetSelectedFig();
	if (FigurePt == NULL)
	{
		pOut->PrintMessage("No Figure Selected Please Select Figure ");
	}
	else {
		pOut->CreateColorToolBar();
		ActionType ColorPick = pManager->GetUserAction();

		if (FillDraw == 'F') {
			switch (ColorPick) {
			case  PICK_BLACK: FigurePt->ChngFillClr(BLACK); break;
			case  PICK_BLUE: FigurePt->ChngFillClr(BLUE); break;
			case  PICK_RED: FigurePt->ChngFillClr(RED); break;
			case  PICK_YELLOW: FigurePt->ChngFillClr(YELLOW); break;
			case  PICK_GREEN: FigurePt->ChngFillClr(GREEN); break;
			case  PICK_ORANGE: FigurePt->ChngFillClr(ORANGE); break;
			}
		}

		if (FillDraw == 'D') {
			switch (ColorPick) {
			case  PICK_BLACK: FigurePt->ChngDrawClr(BLACK); break;
			case  PICK_BLUE: FigurePt->ChngDrawClr(BLUE); break;
			case  PICK_RED: FigurePt->ChngDrawClr(RED); break;
			case  PICK_YELLOW: FigurePt->ChngDrawClr(YELLOW); break;
			case  PICK_GREEN: FigurePt->ChngDrawClr(GREEN); break;
			case  PICK_ORANGE: FigurePt->ChngDrawClr(ORANGE); break;
			}
		}

			pOut->CreateDrawToolBar();

	}
}
	