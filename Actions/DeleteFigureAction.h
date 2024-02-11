#pragma once
#include "Action.h"
#include "CFigure.h"
class DeleteFigureAction :
    public Action
{

private:
    CFigure* Figure;
    CFigure* Backup;

public:
    DeleteFigureAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void undo();
    virtual void redo();
    ~DeleteFigureAction();
};

