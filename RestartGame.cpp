#include "RestartGame.h"

RestartGame::RestartGame(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
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