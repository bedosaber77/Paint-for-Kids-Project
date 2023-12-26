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
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure   // Needs Setter and Getter ANAS IBRAHEM
	
	//-------------------PICK&HIDE-------------------
	CFigure* PickingFig; //Randomed Shape
	color PickingClr;	//Randomed color

	int PickingShapeCount = 0;	//Number of shaped figures to be PICKED
	int PickingColorCount = 0;	//Number of colored figures to be PICKED
	int PickingColoredShapeCount = 0;	//Number of colored shaped figures to be PICKED
	int CorrectPicks = 0;		
	int WrongPicks = 0;

	bool IsPicking = 0;
	
	//-------------------RECORDING-------------------
	Action* RecordActionList[MaxRecActCount]; //List of Recorded Actions
	int RecActCount = 0; //No. of Recorded Actions
	
	bool IsRec = 0;
	bool IsPlayingRec = 0;
	bool IsSoundOn;
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	//Stacks For Undo and Redo Actions
	stack* UndoActs;
	stack* RedoActs;


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


	bool GetSoundStatues();

	// -- Pick & Hide Functions
	CFigure* GetPickingFig();
	color GetPickingColor();
	void SetGameMode(bool);
	bool GetGameMode();
	void PickRand();
	void RestartGame();
	void PickByShape();
	void PickByColor();
	void PickByColoredShapes();
	
	int GetCorrectPicks();
	int GetWrongPicks();
	int GetPickingShapeCount();
	int GetPickingColorCount();
	int GetPickingColoredShapeCount();

	void IncrementCorrectPicks();
	void IncrementWrongPicks();

//--------------------------Undo & Redo-----------------------------
	// -- Undo And Redo Swapping functions
	void AddtoRedo();
	void AddtoUndo();

	void UndoIT();
	void RedoIT();

	void CreateInUndo(Action* x);

	void SetUndoRecordState(bool x);

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	void SaveALL(ofstream& OutFile);
	static string ShapeString(CFigure*);




};

#endif