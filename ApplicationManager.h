#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Action.h"
#include "stack.h"
class stack;
//Main class that manages everything in the application.
class ApplicationManager
{
	enum {
		MaxFigCount = 200,
		MaxRecActCount = 20
	};	//Max no of (figures,RecordedActions,)

private:
	int FigCount;		//Actual number of figures
	int DelFigCount;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* RecycleBin[MaxFigCount]; //List of All deleted figures
	CFigure* SelectedFig; //Pointer to the selected figure   // Needs Setter and Getter ANAS IBRAHEM
	CFigure* PickingFig; 
	color PickingClr;
	Action* RecordActionList[MaxRecActCount]; //List of Recorded Actions
	int RecActCount = 0; //No. of Recorded Actions
	
	bool IsRec = 0;
	bool IsPlayingRec = 0;
	bool IsSoundOn;
	bool Isread = 0;
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	//Stacks For Undo and Redo Actions
	stack* UndoActs;
	stack* RedoActs;

	//boolean variable to delete pAct
	bool toDelete =0;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void RemoveFigure(CFigure* pFig);
	void SelectFigure(CFigure*);
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure* );
	CFigure* GetSelectedFig();
	int GetFigCount(); //Check if the figure list is empty or not
	void ClearFigures();

	// -- Recording Management Functions
	void SetRecordingState(bool);
	bool IsRecording();
	
	void RecordAction(Action*);
	void ClearRecord();
	
	void SetPlayingRecordState(bool);
	bool IsPlayingRecord();
	void PlayRecord();

	int GetRecActCount();
	int GetMaxRecCount();
	//--------------------------Undo & Redo-----------------------------

	bool GetSoundStatues();
	// -- Pick & Hide Functions
	//set & get Picking shape or color
	void PickRand();
	void PickShape();

	// -- Undo And Redo Swapping functions
	void AddtoRedo();
	void AddtoUndo();

	void UndoIT();
	void RedoIT();
	//Functions for managing reading parameters
	bool IsRead();
	void SettoRead();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	void SaveALL(ofstream& OutFile);
	static string ColorString(color C);
	static color StringColor(string C);
	static string ShapeString(CFigure*);
};

#endif