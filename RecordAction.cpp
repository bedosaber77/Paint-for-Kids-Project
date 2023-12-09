#include "RecordAction.h"
#include "RecordAction.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>

RecordAction::RecordAction(ApplicationManager* pApp) :Action(pApp)
{
	if (pManager->GetFigCount() == 0)
	{
		RecActCount = 0;
		RecFigCount = 0;
		Recording = 1;
		for (int i = 0; i < 20; i++)
		{
			RecActList[i] = NULL;
			RecFigList[i] = NULL;
		}
		pOut->PrintMessage("Recording Started.");
	}
	else
	{
		pOut->PrintMessage("You can only record from a clear drawing area");
		pManager->ExecuteAction(STOP_REC);
	}

}

void RecordAction::ReadActionParameters()
{
}

void RecordAction::Execute()
{
}

void RecordAction::RecordOperation(Action* RecAct)
{
	if (RecActCount < 20)
		RecActList[RecActCount++] = RecAct;
	else
	{
		pOut = pManager->GetOutput();
		pOut->PrintMessage("You reached the MAX recording operations(20). ");
		pManager->ExecuteAction(STOP_REC);
	}
}

void RecordAction::RecordFigure(CFigure* RecFig)
{
	RecFigList[RecFigCount++] = RecFig;
}

bool RecordAction::IsRecording()
{
	return Recording;
}


RecordAction::~RecordAction()
{
	pOut->PrintMessage("Recording Ended.");
	std::cout << RecActCount;
	std::cout << RecFigCount;
	pOut->ClearDrawArea();
	for (int i = 0; i < 20; i++)
	{
		Sleep(1000);
		RecActList[i]->Execute();
		pManager->UpdateInterface();
	}
}