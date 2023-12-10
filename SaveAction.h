#pragma once
#include "Action.h"
#include <fstream>
using namespace std;

class SaveAction :public Action
{
	ofstream Outfile;
	string userinput;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

