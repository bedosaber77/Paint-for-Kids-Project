#pragma once
#include "ApplicationManager.h"

class Action;
class mystack
{
private:
	Action** ActListPtr;
	int top;
public:
	mystack();
	bool isFilled();
	bool isEmpty();
	void push(Action* x);
	void pop();
	Action* Top();
};
