#pragma once

#include "..\ApplicationManager.h"

class Action;
class stack
{
	private:
	Action* ActListPtr[5];
	int topelement;
	bool IsRec;
	bool IsPlaying;
public:
	stack();
	bool isFilled();
	bool isEmpty();
	void push(Action* x);
	void SetIsRec(bool x);
	void SetIsPlaying(bool x);
	void Destruct();
	void pop();
	void clear();
	Action* Top();
	~stack();
	
};


