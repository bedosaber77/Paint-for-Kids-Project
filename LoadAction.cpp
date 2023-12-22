#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"


LoadAction::LoadAction(ApplicationManager* pApp):Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Enter File Name");
	File_Name = pIn->GetSrting(pOut);
	File_Name += ".txt";
}

void LoadAction::Execute()
{
	string str;
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	infile.open("Saves\\" + File_Name);
	if (infile.fail()) {
		pOut->PrintMessage("Failed To Load " + File_Name);
	}
	else {
		pManager->ClearFigures();
		infile >> str;
		UI.DrawColor = ApplicationManager::StringColor(str);
		infile >> str;
		UI.FillColor= ApplicationManager::StringColor(str);
		int n, id;
		CFigure* NewFig=NULL;
		infile >> n;
		for (int i = 0; i < n; i++)
		{
			infile >>str>>id;
			if (str == "RECT")
			{
				NewFig = new CRectangle(id);
				NewFig->Load(infile);
				NewFig->SetSelected(false);
			}
			if (str == "CIRC")
			{
				NewFig = new CCircle(id);
				NewFig->Load(infile);
				NewFig->SetSelected(false);
			}
			if (str == "HEXAGON")
			{
				NewFig = new CHexagon(id);
				NewFig->Load(infile);
				NewFig->SetSelected(false);
			}
			if (str == "SQUARE")
			{
				NewFig = new CSquare(id);
				NewFig->Load(infile);
				NewFig->SetSelected(false);
			}
			if (str == "TRI")
			{
				NewFig = new CTriangle(id);
				NewFig->Load(infile);
				NewFig->SetSelected(false);
			}
			pManager->AddFigure(NewFig);
		}
	}
}