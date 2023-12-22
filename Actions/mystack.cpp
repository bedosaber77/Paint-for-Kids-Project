#include "mystack.h"

mystack::mystack()
{
	top = 0;
	ActListPtr = new Action* [5];
	for (int i = 0; i < 5; i++) {
		ActListPtr[i] = NULL;
	}
}

bool mystack::isFilled()
{
	return (top == 5);
}

bool mystack::isEmpty()
{
	return (top == 0);
}

void mystack::push(Action* x)
{
	if (isFilled()) {
		for (int i = 1; i < 5; i++) {
			ActListPtr[i - 1] = ActListPtr[i];
		}
		ActListPtr[top - 1] = x;
	}
	else {
		ActListPtr[top] = x;
		top++;
	}
}

void mystack::pop()
{
	delete ActListPtr[--top];
}

Action* mystack::Top()
{
	return ActListPtr[top-1];
}