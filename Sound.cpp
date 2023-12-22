#include "Sound.h"
#include "GUI\\UI_Info.h"
#include"GUI//Output.h"
#include "ApplicationManager.h"
Sound::Sound(ApplicationManager* pApp):Action(pApp)
{
}

void Sound::ReadActionParameters()
{
	
}

void Sound::Execute()
{
	Output* pOut=pManager->GetOutput();
	
		pOut->PrintMessage("Sound IS ON");
		UI.isSoundON = true;
}
