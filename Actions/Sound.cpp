#include "Sound.h"
#include "UI_Info.h"
#include "Output.h"
#include "..\ApplicationManager.h"
Sound::Sound(ApplicationManager* pApp):Action(pApp)
{
}

void Sound::ReadActionParameters()
{
	
}

void Sound::Execute()
{
	Output* pOut= pManager->GetOutput();
	
		pOut->PrintMessage("Sound IS ON");
		UI.isSoundON = true;
}

void Sound::undo()
{
}

void Sound::redo()
{
}
