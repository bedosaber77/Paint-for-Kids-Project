
#pragma once
#include "Actions/Action.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"


class RecordAction :public Action
{
	Action* RecActList[20];
	int RecActCount = 0;
	CFigure* RecFigList[20];
	int RecFigCount = 0;
	Output* pOut = pManager->GetOutput();


public:

	RecordAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	void RecordOperation(Action*);
	void RecordFigure(CFigure*);
	bool IsRecording();
	~RecordAction();
};

