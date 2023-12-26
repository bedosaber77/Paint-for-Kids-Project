#include "MuteAction.h"
#include "UI_Info.h"
#include "Output.h"
#include "..\ApplicationManager.h"
MuteAction::MuteAction(ApplicationManager* pApp):Action(pApp)
{
}

void MuteAction::ReadActionParameters()
{
}

void MuteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	UI.isSoundON = false;
	pOut->PrintMessage("Sound IS OFF");
}

void MuteAction::undo()
{
}

void MuteAction::redo()
{
}