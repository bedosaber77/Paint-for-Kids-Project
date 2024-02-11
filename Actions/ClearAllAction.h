#pragma once
#include "Action.h"

    //Add Clear All Action class
    class ClearAllAction : public Action
    {
    public:
        //Constructor
        ClearAllAction(ApplicationManager* pApp);

        
        virtual void ReadActionParameters();

        virtual void Execute();

        virtual void undo();
        virtual void redo();


    };

