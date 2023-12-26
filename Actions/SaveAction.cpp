#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Enter File Name");
	File_Name = pIn->GetSrting(pOut);
}

void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Outfile.open("Saves\\"+ File_Name +".txt");
	pManager->SaveALL(Outfile);
	pOut->PrintMessage("SAVED " + File_Name + " Done");
	Outfile.close();
}

void SaveAction::undo()
{
}

void SaveAction::redo()
{
}

