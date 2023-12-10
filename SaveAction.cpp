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
	userinput = pIn->GetSrting(pOut);
	userinput += ".txt";
}

void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Outfile.open(userinput);
	pManager->SaveALL(Outfile);
	pOut->PrintMessage("SAVED " + userinput + " Done");
	Outfile.close();
}
