#ifndef RESTART_GAME
#define RESTART_GAME

#include "Action.h"
#include "CFigure.h"
#include "../ApplicationManager.h"

class RestartGame :public Action
{
	Output* pOut;
public:
	RestartGame(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	virtual void redo();
};
#endif

