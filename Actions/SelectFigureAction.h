#pragma once
#include "Action.h"
class SelectFigureAction :
    public Action
{

private :

    Point SelectionPoint;


public :


    SelectFigureAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();





};

