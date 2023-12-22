#include "stack.h"


stack::stack(): topelement(0)
{
	for (int i = 0; i < 5; i++) {
		ActListPtr[i] = NULL;
	}
}

bool stack::isFilled()
{
	return (topelement == 5);
}

bool stack::isEmpty()
{
	return (topelement == 0);
}

void stack::push(Action* x)
{
	if (isFilled()) {
		delete ActListPtr[0];
		for (int i = 1; i < 5; i++) {
			ActListPtr[i - 1] = ActListPtr[i];
		}
		ActListPtr[topelement - 1] = x;
	}

	else {
		ActListPtr[topelement] = x;
		topelement++;
	}
}

void stack::pop()
{
	ActListPtr[--topelement] = NULL;

}

void stack::clear()
{
	if (!isEmpty()) {
		for (int i = 0; i < topelement; i++) {
			ActListPtr[i] = NULL;
		}
		topelement = 0;

	}
}

Action* stack::Top()
{
	return ActListPtr[topelement-1];
}

stack::~stack()
{

}

