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
#include "Sound.h"
#include "MuteAction.h"
#include "UndoAction.h"
#include "RedoAction.h"
#include "MoveFigureByPoint.h"
#include "MoveByDragging.h"



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
	DelFigCount = 0;

		
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
	return pIn->GetUserAction();		
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
			toDelete = 1;
			break;
		// ########################## Load Figures ##########################
		case LOAD:
			pAct = new LoadAction(this);
			break;
		// ########################## Delete Figure ##########################

		case ERASE:
			pAct = new DeleteFigureAction(this);
			UndoActs->push(pAct);
			toDelete = 0;
			RedoActs->clear();
			break;

		// ########################## Move Figure ##########################

		case MOVE:
			pAct = new MoveFigureByPoint(this);
			break;

		case MOVEBYDRAGGING:
			pAct = new MoveByDragging(this);
			break;


		// ########################## Change Color ##########################

		case FILL_COLOR_PICK:
			pAct = new ChangeColorAction(this,'F');
			toDelete = 0;
			UndoActs->push(pAct);
			RedoActs->clear();
			break;

		case BORDER_COLOR_PICK:
			pAct = new ChangeColorAction(this,'D');
			toDelete = 0;
			UndoActs->push(pAct);
			RedoActs->clear();
			break;


			// ########################## Add Figure ##########################
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			toDelete = 0;
			UndoActs->push(pAct);
			RedoActs->clear();
			break;

		case DRAW_HEX:
			pAct = new AddHexAction(this);
			toDelete = 0;
			UndoActs->push(pAct);
			RedoActs->clear();
			break;

		case DRAW_SQU:
			pAct = new AddSquAction(this);
			toDelete = 0;
			UndoActs->push(pAct);
			RedoActs->clear();
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			toDelete = 0;
			UndoActs->push(pAct);
			RedoActs->clear();
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			toDelete = 0;
			UndoActs->push(pAct);
			RedoActs->clear();
			break;

		case CLEARALL:
			pAct = new ClearAllAction(this);
			toDelete = 1;
			break;

		// ########################## Recording ##########################
			
		case START_REC:
			pAct = new StartRecordAction(this);
			toDelete = 1;
			break;

		case STOP_REC:
			pAct = new StopRecordAction(this);
			toDelete = 1;
			break;

		case PLAY_REC:
			pAct = new PlayRecordAction(this);
			toDelete = 1;
			break;

		case SHAPE_PLAY_PICK:
			pAct = new PickByShapeAction(this);
			break;

		case SELECT:
			pAct = new SelectFigureAction(this);
			toDelete = 1;
			break;

			// ########################## Undo & Redo ##########################

		case UNDO:
			pAct = new UndoAction(this);
			toDelete = 1;
			break;

		case REDO:
			pAct = new RedoAction(this);
			toDelete = 1;
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
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	if (IsRecording())
	{
		switch (ActType)
		{
		case START_REC:
		case PLAY_REC:
		case SAVE_GRAPH:
		case LOAD:
			delete pAct;
			pAct = NULL;
			break;
		}
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		if (!IsRecording() && toDelete)
		{
			delete pAct;	//You may need to change this line depending to your implementation of undo and redo
			pAct = NULL;
		}
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	bool found = 0;
	int i = 0;
	while (i < DelFigCount && !found) {
		if (pFig == RecycleBin[i]) {
			found = 1;
			for (int j = i; j < DelFigCount - 1; j++)
			{
				RecycleBin[j] = RecycleBin[j + 1]; // Shifting All Remaining Figures
			}
			RecycleBin[DelFigCount - 1] = NULL;
			DelFigCount--;
		}
		i++;
	}
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
	if (DelFigCount < MaxFigCount)
		RecycleBin[DelFigCount++] = pFig;
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
	for (int i = 0; i < DelFigCount; i++)
		delete RecycleBin[i];
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
	}
	FigCount = 0;
	DelFigCount = 0;
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
		RecordActionList[i] = NULL;
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
	pOut->ClearDrawArea();

	//ClearAll Alter ..do it in playrec class
	for (int i = 0; i < FigCount; i++)
		FigList[i] = NULL;

	for (int i = 0; i < RecActCount; i++)
	{
		Sleep(1000);
		RecordActionList[i]->Execute();
		UpdateInterface();
	}
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

void ApplicationManager::PickRand()
{
	int R = rand() % FigCount;
	PickingFig = FigList[R];
	PickingClr = FigList[R]->GetColor();
}


void ApplicationManager::PickShape()
{
	pOut->PrintMessage("Pick all " + ShapeString(PickingFig) + " Shapes.");
	ActionType Act;

	bool cont = 1;
	while (cont)
	{
		/*Act = RESTART_PLAY;
		switch (Act = GetUserAction())
		{
		case SHAPE_PLAY_PICK:
		case COLORED_SHAPE_PLAY_PICK:
		case COLOR_PLAY_PICK:
		case RESTART_PLAY:
			//return back all figs
			//start the new game
		case TO_DRAW:
			//return back all figs
			cont = 0;
			break;

		default:
		*/
		Point PickPoint;
		pIn->GetPointClicked(PickPoint.x, PickPoint.y);
		CFigure* PickedFig = GetFigure(PickPoint.x, PickPoint.y);

		if (PickingFig->GetShape() == PickedFig->GetShape())
			PickedFig->SetHidden(1);

		UpdateInterface();

	}
}

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

bool ApplicationManager::IsRead()
{
	return Isread;
}

void ApplicationManager::SettoRead()
{
	Isread = true;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if (FigList[i] != NULL && !(FigList[i]->GetHidden()))
		 FigList[i]->Draw(pOut);	

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
}
void ApplicationManager::SaveALL(ofstream& OutFile)
{
	OutFile <<ColorString(UI.DrawColor)<<'\t'<<ColorString(UI.FillColor)<<'\n'<<FigCount<<'\n';

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
			FigList[i]->Save(OutFile);
	}
}
string ApplicationManager::ColorString(color C)
{

		if (C == BLACK)    return "BLACK";
		if (C == GREEN)    return "GREEN";
		if (C == ORANGE)   return "ORANGE";
		if (C == YELLOW)   return "YELLOW";
		if (C == RED)      return "RED";
		if (C == BLUE)     return "BLUE";
}
color ApplicationManager::StringColor(string C)
{
	if (C == "BLACK")    return BLACK ;
	if (C == "GREEN")    return GREEN;
	if (C == "ORANGE")   return ORANGE;
	if (C == "YELLOW")   return YELLOW;
	if (C == "RED")      return RED;
	if (C == "BLUE")     return BLUE;
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
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < DelFigCount; i++)
		delete RecycleBin[i];
	delete pIn;
	delete pOut;
	
}
