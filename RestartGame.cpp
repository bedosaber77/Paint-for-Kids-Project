#include "RestartGame.h"

RestartGame::RestartGame(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
	pManager->PickRand();
}

void RestartGame::ReadActionParameters()
{
}

void RestartGame::Execute()
{
	pManager->RestartGame();
}

void RestartGame::undo()
{
}

void RestartGame::redo()
{
}