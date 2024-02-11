#pragma once
#include "Action.h"
#include "stack.h"
class RedoAction :
    public Action
{
public:
    RedoAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();

    virtual void undo();
    virtual void redo();
};
