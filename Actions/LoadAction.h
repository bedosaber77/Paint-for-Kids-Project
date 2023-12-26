#pragma once
#include "Action.h"
#include <fstream>
using namespace std;
class LoadAction : public Action
{
	ifstream infile;
	string File_Name;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};

