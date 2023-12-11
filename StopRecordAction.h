#pragma once
#include "Actions/Action.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"

class StopRecordAction :public Action
{
	Output* pOut = pManager->GetOutput();

public:
	StopRecordAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};