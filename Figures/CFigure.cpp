#include "CFigure.h"
#include "../ApplicationManager.h"



int CFigure::id = 1;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = id++;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

bool CFigure::IsInclude(Point) const
{
	return false;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

color CFigure::getDrawClr()
{
	return FigGfxInfo.DrawClr;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

color CFigure::getFillClr()
{
		return FigGfxInfo.FillClr;
}

bool CFigure::IsFilled()
{
	return FigGfxInfo.isFilled;
}

void CFigure::PrintInfo(Output* pOut)
{
	string Info = "ID : ";
	Info += to_string(ID) + " | ";
	Info += "D Color : ";
	Info += ApplicationManager::ColorString(FigGfxInfo.DrawClr)+ " | ";
    Info += "F Color : ";
	Info += ApplicationManager::ColorString(FigGfxInfo.FillClr) + " | ";
	pOut->PrintMessage(Info);
}



