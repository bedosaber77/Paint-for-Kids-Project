#pragma once
#include "Action.h"
#include "stack.h"  

class UndoAction :
    public Action
{
public:
    UndoAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void undo();
    virtual void redo();
};

