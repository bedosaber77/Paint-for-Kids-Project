#pragma once
#include "Action.h"
#include "CFigure.h"
class DeleteFigureAction :
    public Action
{

private:
    CFigure* Figure;


public:


    DeleteFigureAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();





};

