#pragma once
#include "Action.h"
class ChangeColorAction :
    public Action
{

private:
    char FillDraw;


public:


    ChangeColorAction(ApplicationManager* pApp, char c);
    virtual void ReadActionParameters();
    virtual void Execute();





};

