#pragma once
#include "Action.h"
#include "CFigure.h"
class ChangeColorAction :
    public Action
{

private:
    char FillDraw;
    color ColorPicked;
    color LastDrawClr;
    color LastFillClr;
    bool wasFilled;
    CFigure* FigurePt;
    ActionType ColorPick;

public:


    ChangeColorAction(ApplicationManager* pApp, char c);
    virtual void ReadActionParameters();
    virtual void Execute();



    virtual void undo();
    virtual void redo();

};

