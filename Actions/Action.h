#ifndef ACTION_H
#define ACTION_H
#include "CFigure.h"
#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	Output* pOut;
	bool Recording = 0;
public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;

	virtual void undo() = 0; //Undo for Action
	virtual void redo() = 0; //Redo for Undo Action
};

#endif