#pragma once

#include "ApplicationManager.h"

class Action;
class stack
{
	private:
	Action* ActListPtr[5];
	int topelement;
public:
	stack();
	bool isFilled();
	bool isEmpty();
	void push(Action* x);
	
	void pop();
	void clear();
	Action* Top();
	~stack();
	
};


