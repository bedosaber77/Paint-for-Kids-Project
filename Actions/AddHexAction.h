#pragma once
#include "Action.h"
class AddHexAction :
    public Action
{

	private:
		CFigure* H;
		CFigure* tmp;
		Point P1; //Hexagon Center Point
		GfxInfo HexGfxInfo;
	public:
		AddHexAction(ApplicationManager* pApp);

		//Reads Hexagon parameters
		virtual void ReadActionParameters();

		//Add Hexagon to the ApplicationManager
		virtual void Execute();

		virtual void undo();
		virtual void redo();
		~AddHexAction();
};

