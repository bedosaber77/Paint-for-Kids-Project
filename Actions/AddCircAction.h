#pragma once
#include "Action.h"


	//Add Circle Action class
	class AddCircAction : public Action
	{
	private:
		CFigure* C;
		CFigure* tmp;
		Point P1, P2; //Center And Point On Circle
		GfxInfo CircGfxInfo;
	public:
		AddCircAction(ApplicationManager *pApp);

		//Reads Circle parameters
		virtual void ReadActionParameters();

		//Add Circle to the ApplicationManager
		virtual void Execute();

		virtual void undo();
		virtual void redo();
		~AddCircAction();
	};



