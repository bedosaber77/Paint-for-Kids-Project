
#pragma once
#include "Actions/Action.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"


class RecordAction :public Action
{
	Output* pOut = pManager->GetOutput();
public:

	RecordAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};

