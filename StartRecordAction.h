#ifndef START_RECORD_ACTION
#define START_RECORD_ACTION

#include "Actions/Action.h"
#include "..\ApplicationManager.h"

class StartRecordAction :public Action
{
	Output* pOut = pManager->GetOutput();
public:

	StartRecordAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif
