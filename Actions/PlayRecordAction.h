#ifndef PLAY_RECORD_ACTION
#define PLAY_RECORD_ACTION

#include "Action.h"
#include "..\ApplicationManager.h"

class PlayRecordAction :public Action
{
	Output* pOut = pManager->GetOutput();
public:

	PlayRecordAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	virtual void redo();

};

#endif