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



//Constructor
ApplicationManager::ApplicationManager()
{
	SelectedFig = NULL; ////////////////// ANAS IBRAHEM WANT TO ASK

	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
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
		break;
		// ########################## Load Figures ##########################
	case LOAD:
		pAct = new LoadAction(this);
		break;
		// ########################## Delete Figure ##########################

		case ERASE:
			pAct = new DeleteFigureAction(this);
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

		case SHAPE_PLAY_PICK:
			//pAct = new PickByShapeAction(this);

		case SELECT:
			pAct = new SelectFigureAction(this);
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

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	/*if (IsRecording())
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
	}*/

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		if (!IsRecording())
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
			delete FigList[i];
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

void ApplicationManager::SelectFigure(CFigure* SelectFig)
{
	if (SelectFig != NULL && SelectFig->IsSelected() == false)
	{
		SelectFig->SetSelected(true);
		SetSelectedFig(SelectFig);
		SelectFig->PrintInfo(pOut);

	}
	else if (SelectFig != NULL && SelectFig->IsSelected() == true) {
		SelectFig->SetSelected(false);
		SelectFig = NULL;
		SetSelectedFig(SelectFig);
		pOut->PrintMessage("Figure is Deselected");
	}
	else if (SelectFig == NULL)
		pOut->PrintMessage("No Figure Selected, Please Click On Figure");
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
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
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

CFigure* ApplicationManager::Rand()
{
	int R = rand() % FigCount;
	PickingFig = FigList[R];
	return FigList[R];
}

color ApplicationManager::ColorRand()
{
	return Rand()->GetColor();
}

void ApplicationManager::PickShape()
{
	while (true)
	{
		switch (GetUserAction())
		{
		case SHAPE_PLAY_PICK:
		case COLORED_SHAPE_PLAY_PICK:
		case COLOR_PLAY_PICK:
		case RESTART_PLAY:
		case TO_DRAW:
			//
			break;
		default:
			Point SelectionPoint;
			pIn->GetPointClicked(SelectionPoint.x, SelectionPoint.y);
			CFigure* SF = GetFigure(SelectionPoint.x, SelectionPoint.y);
			//if(dynamic_cast<SF>(PickingFig))
		}
	}
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
	delete pIn;
	delete pOut;
	
}
