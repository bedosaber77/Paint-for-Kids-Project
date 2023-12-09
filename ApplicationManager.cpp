#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddCircAction.h"
#include "AddSquAction.h"
#include "AddTriAction.h"
#include "AddHexAction.h"
#include "SelectFigureAction.h"
#include "ChangeColorAction.h"
#include "DeleteFigureAction.h"
#include "RecordAction.h"

RecordAction* pRecAct = NULL;




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
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{


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

			////////////////////////////
		case START_REC:
		{
			if (pRecAct == NULL)
			{
				pRecAct = new RecordAction(this);
			}
		}
		break;

		case STOP_REC:
		{
			if (pRecAct != NULL)
			{
				delete pRecAct;
				pRecAct = NULL;
			}
		}
		break;

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
	if (pRecAct != NULL)
	{
		switch (ActType)
		{
		case START_REC:
		case STOP_REC:
		case PLAY_REC:
		case SAVE_GRAPH:
		case LOAD:
			pAct = NULL;
			break;
		default:
			pRecAct->RecordOperation(pAct);
		}
	}

	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation of undo and redo
		pAct = NULL;
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
	if (pRecAct != NULL)
		pRecAct->RecordFigure(pFig);
}


void ApplicationManager::RemoveFigure(CFigure* pFig)
{
	bool found  = 0;
	int i = 0;
	while(i < FigCount && !found)
	{  
		if (pFig == FigList[i])
		 {
			found = 1;
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[j] = FigList[j + 1]; // Shifting All Remaining Figures
			}
			delete FigList[FigCount];
			FigList[--FigCount] = NULL;
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


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if(FigList[i]!=NULL)
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
