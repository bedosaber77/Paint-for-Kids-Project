#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddCircAction.h"
#include "AddSquAction.h"
#include "AddTriAction.h"
#include "AddHexAction.h"
#include "SelectFigureAction.h"
#include "ChangeColorAction.h"
#include "DeleteFigureAction.h"
#include "ClearAllAction.h"
#include "StartRecordAction.h"
#include "StopRecordAction.h"
#include "PlayRecordAction.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "PickByShapeAction.h"
#include "PickByColorAction.h"
#include "PickByColoredShapes.h"
#include "RestartGame.h"
#include "Sound.h"
#include "MuteAction.h"
#include "UndoAction.h"
#include "RedoAction.h"
#include "MoveFigureByPoint.h"
#include "MoveByDragging.h"
#include "ResizeAction.h"
#include "ExitAction.h"
#include "GUI/Output.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	SelectedFig = NULL; ////////////////// ANAS IBRAHEM WANT TO ASK

	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	UndoActs = new stack();
	RedoActs = new stack();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	//Create an array of Recorded Actions pointers and set them to NULL		
	for (int i = 0; i < MaxRecActCount; i++)
		RecordActionList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(0,0,0);		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL; //Pointer to the current Action
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{


		// ########################## Save Figures ##########################
		case SAVE_GRAPH:
			pAct = new SaveAction(this);
			break;
		// ########################## Load Figures ##########################
		case LOAD:
			pAct = new LoadAction(this);
			break;
		// ########################## Delete Figure ##########################

		case ERASE:
			pAct = new DeleteFigureAction(this);
			break;

		// ########################## Move Figure ##########################

		case MOVE:
			pAct = new MoveFigureByPoint(this);
			break;

		case MOVEBYDRAGGING:
			pAct = new MoveByDragging(this);
			break;
		// ########################## Resize Figure ##########################

		case RESIZE:
			pAct = new ResizeAction(this);
			break;

		// ########################## Change Color ##########################

		case FILL_COLOR_PICK:
			pAct = new ChangeColorAction(this,'F');
			break;

		case BORDER_COLOR_PICK:
			pAct = new ChangeColorAction(this,'D');
			break;


			// ########################## Add Figure ##########################
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;

		case DRAW_SQU:
			pAct = new AddSquAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case CLEARALL:
			pAct = new ClearAllAction(this);
			break;

		// ########################## Recording ##########################
			
		case START_REC:
			pAct = new StartRecordAction(this);
			break;

		case STOP_REC:
			pAct = new StopRecordAction(this);
			break;

		case PLAY_REC:
			pAct = new PlayRecordAction(this);
			break;

			// ########################## PICK & HIDE ##########################

		case SHAPE_PLAY_PICK:
			pAct = new PickByShapeAction(this);
			break;

		case COLOR_PLAY_PICK:
			pAct = new PickByColorAction(this);
			break;

		case COLORED_SHAPE_PLAY_PICK:
			pAct = new PickByColoredShapesAction(this);
			break;

		case RESTART_PLAY:
			pAct = new class RestartGame(this);
			break;

			///////////////////////////////////////////////////////////////////

		case SELECT:
			pAct = new SelectFigureAction(this);
			break;

			// ########################## Undo & Redo ##########################

		case UNDO:
			pAct = new UndoAction(this);
			break;

		case REDO:
			pAct = new RedoAction(this);
			break;

		case SHAPES_PICK :
			pOut->CreateShapesToolBar();
			break;

		case TO_DRAW:
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->CreatePlayToolBar();
			break;

		case UNMUTE:
			pAct = new Sound(this);
			break;
		case MUTE:
			pAct = new MuteAction(this);
			break;
		case EXIT:
			pAct = new ExitAction(this);
			break;

		case DRAWING_AREA:
			return;
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();	//Execute
		switch (ActType)
		{
		case PLAY_REC:
		case START_REC:
		case STOP_REC:

		case SHAPE_PLAY_PICK:
		case COLOR_PLAY_PICK:
		case COLORED_SHAPE_PLAY_PICK:
		case RESTART_PLAY:

		case SAVE_GRAPH:
		case LOAD:

		case EXIT:
			delete pAct;
			pAct = NULL;
			break;

		default:
			if (IsRecording() /*&& ActType != START_REC*/)
			{
				RecordAction(pAct);
				if (GetRecActCount() == GetMaxRecCount())
					ExecuteAction(STOP_REC);
			}
			else
			{
				switch (ActType)
				{
				case SELECT:
				case UNDO:
				case REDO:
					delete pAct;
					pAct = NULL;
				}
			}
		}
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}


void ApplicationManager::RemoveFigure(CFigure* pFig)
{
	bool found = 0;
	int i = 0;
	while (i < FigCount && !found)
	{
		if (pFig == FigList[i])
		{
			found = 1;
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[j] = FigList[j + 1]; // Shifting All Remaining Figures
			}
			FigList[FigCount - 1] = NULL;
			FigCount--;
		}
		i++;

	}
}

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

		Point Search;
		Search.x = x;
		Search.y = y;

		for (int i = FigCount - 1; i >= 0; i--)
		{
			if (FigList[i]->IsInclude(Search))
			{
				return FigList[i];
			}
		}

		return NULL;
	

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

void ApplicationManager::SetSelectedFig(CFigure* F) 
{

	if (SelectedFig != NULL) 
		SelectedFig->SetSelected(false); 

	SelectedFig = F;
}

CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}

int ApplicationManager::GetFigCount()
{
	return FigCount;
}

void ApplicationManager::ClearFigures()
{
	UndoActs->clear();
	RedoActs->clear();
	
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	SelectedFig = NULL;
	pOut->ResetColors();//Anas Magdy: Ask if this is the right Place or Not
}

//==================================================================================//
//							Record Management Functions							//
//==================================================================================//

void ApplicationManager::SetRecordingState(bool RecState)
{
	IsRec = RecState;
}

bool ApplicationManager::IsRecording()
{
	return IsRec;
}

void ApplicationManager::RecordAction(Action* pRecAct)
{
	if (GetRecActCount() < GetMaxRecCount())
		RecordActionList[RecActCount++] = pRecAct;
}

void ApplicationManager::ClearRecord()
{
	for (int i = 0; i < MaxRecActCount; i++)
	{
		delete RecordActionList[i];
		RecordActionList[i] = NULL;
	}
	RecActCount = 0;
}

void ApplicationManager::SetPlayingRecordState(bool PRState)
{
	IsPlayingRec = PRState;
}

bool ApplicationManager::IsPlayingRecord()
{
	return IsPlayingRec;
}

void ApplicationManager::PlayRecord()
{
	UndoActs->SetIsPlaying(true);
	RedoActs->SetIsPlaying(true);
		for (int i = 0; i < RecActCount; i++)
		{
			Sleep(1000);
		if(RecordActionList[i] !=NULL)
				RecordActionList[i]->Execute();
			UpdateInterface();
		}
		Sleep(1000);
		UndoActs->SetIsPlaying(false);
		RedoActs->SetIsPlaying(false);
}

int ApplicationManager::GetRecActCount()
{
	return RecActCount;
}

int ApplicationManager::GetMaxRecCount()
{
	return MaxRecActCount;
}

bool ApplicationManager::GetSoundStatues()
{
	return UI.isSoundON;
}

CFigure* ApplicationManager::GetPickingFig()
{
	return PickingFig;
}

color ApplicationManager::GetPickingColor()
{
	return PickingClr;
}

void ApplicationManager::SetGameMode(bool p)
{
	IsPicking = p;
}

bool ApplicationManager::GetGameMode()
{
	return IsPicking;
}

void ApplicationManager::PickRand()
{
	int R = rand() % FigCount;
	PickingFig = FigList[R];
	PickingClr = FigList[R]->GetColor();
	PickingShapeCount = 0;
	PickingColorCount = 0;
	PickingColoredShapeCount=0;

	for (int i = 0; i < FigCount; i++)
	{
		if (PickingFig->GetShape() == FigList[i]->GetShape())
			PickingShapeCount++;

		if (PickingFig->GetColor() == FigList[i]->GetColor())
			PickingColorCount++;

		if (PickingFig->GetColor() == FigList[i]->GetColor() && PickingFig->GetShape() == FigList[i]->GetShape())
			PickingColoredShapeCount++;
	}
}

void ApplicationManager::RestartGame()
{
	PickingShapeCount = 0;
	PickingColorCount = 0;
	PickingColoredShapeCount = 0;
	CorrectPicks = 0;
	WrongPicks = 0;

	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetHidden(false);

		if (PickingFig->GetShape() == FigList[i]->GetShape())
			PickingShapeCount++;

		if (PickingFig->GetColor() == FigList[i]->GetColor())
			PickingColorCount++;

		if (PickingFig->GetColor() == FigList[i]->GetColor() && PickingFig->GetShape() == FigList[i]->GetShape())
			PickingColoredShapeCount++;
	}

	UpdateInterface();
}



int ApplicationManager::GetCorrectPicks()
{
	return CorrectPicks;
}

int ApplicationManager::GetWrongPicks()
{
	return WrongPicks;
}

int ApplicationManager::GetPickingShapeCount()
{
	return PickingShapeCount;
}

int ApplicationManager::GetPickingColorCount()
{
	return PickingColorCount;
}

int ApplicationManager::GetPickingColoredShapeCount()
{
	return PickingColoredShapeCount;
}

void ApplicationManager::IncrementCorrectPicks()
{
	CorrectPicks++;
}

void ApplicationManager::IncrementWrongPicks()
{
	WrongPicks++;
}


//==================================================================================//
//							    Undo & Redo Functions     							//
//==================================================================================//



void ApplicationManager::AddtoRedo()
{
	if(!UndoActs->isEmpty())
		RedoActs->push(UndoActs->Top());
	
}

void ApplicationManager::AddtoUndo()
{
	if (!RedoActs->isEmpty())
		UndoActs->push(RedoActs->Top());

}

void ApplicationManager::UndoIT()
{
	if (!UndoActs->isEmpty()) {
		UndoActs->Top()->undo();
		UndoActs->pop();
	}
}

void ApplicationManager::RedoIT()
{
	if (!RedoActs->isEmpty()) {
		RedoActs->Top()->redo();
		RedoActs->pop();
	}
}

void ApplicationManager::CreateInUndo(Action* x)
{
	UndoActs->push(x);
	RedoActs->clear();
}

void ApplicationManager::SetUndoRecordState(bool x)
{
	UndoActs->SetIsRec(x);
	RedoActs->SetIsRec(x);
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->setBuffering(true);
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if (FigList[i] != NULL && !(FigList[i]->GetHidden()))
		 FigList[i]->Draw(pOut);	

	//Redraw the toolbar and the status bar To Avoid Shapes On Thems
	pOut->RedrawStatusBar();
	pOut->ClearToolBar();
	switch (UI.InterfaceMode)
	{
	case MODE_COLORS:
		pOut->CreateColorToolBar();
		break;
	case MODE_DRAW:
		pOut->CreateDrawToolBar();
		break;
	case MODE_PLAY:
		pOut->CreatePlayToolBar();
		break;
	case MODE_SHAPES:
		pOut->CreateShapesToolBar();
		break;


	}	
	pOut->updateBuffer();
	pOut->setBuffering(false);
}
void ApplicationManager::SaveALL(ofstream& OutFile)
{
	OutFile << Output::ColorString(UI.DrawColor)<<'\t'<< Output::ColorString(UI.FillColor)<<'\n'<<FigCount<<'\n';

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
			FigList[i]->Save(OutFile);
	}
}

string ApplicationManager::ShapeString(CFigure* F)
{
	CFigure::Shape S = F->GetShape();
	switch (S)
	{
	case CFigure::RECTANGLE:
		return "RECTANGLE";
		break;

	case CFigure::TRIANGLE:
		return "TRIANGLE";
		break;

	case CFigure::CIRCLE:
		return "CIRCLE";
		break;

	case CFigure::SQUARE:
		return "SQUARE";
		break;

	case CFigure::HEXAGON:
		return "HEXAGON";
		break;


	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	delete UndoActs;
	delete RedoActs;
	delete pIn;
	delete pOut;
	
}
