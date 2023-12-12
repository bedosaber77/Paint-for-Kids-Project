#ifndef STOP_RECORD_ACTION
#define STOP_RECORD_ACTION

#include "Actions/Action.h"
#include "..\ApplicationManager.h"

class StopRecordAction :public Action
{
	Output* pOut = pManager->GetOutput();

public:
	StopRecordAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif