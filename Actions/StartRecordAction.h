#ifndef START_RECORD_ACTION
#define START_RECORD_ACTION

#include "Action.h"
#include "..\ApplicationManager.h"

class StartRecordAction :public Action
{
	Output* pOut = pManager->GetOutput();
public:

	StartRecordAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};

#endif
