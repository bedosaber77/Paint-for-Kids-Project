#include "CFigure.h"
#include "../ApplicationManager.h"



int CFigure::id = 1;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = id++;
	Hidden = false;
}

CFigure::CFigure(int id)
{
	ID = id;
	Hidden = false;
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

color CFigure::GetColor()
{
	return this->FigGfxInfo.FillClr;
}

CFigure::Shape CFigure::GetShape()
{
	return this->S;
}

void CFigure::addToInfo(string s)
{
	Info += s;
}

void CFigure::SetHidden(bool H)
{
	Hidden = H;
}

bool CFigure::GetHidden()
{
	return Hidden;
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
	Info += "ID : ";
	Info += to_string(ID) + " | ";
	Info += "D Color : ";
	Info += ApplicationManager::ColorString(FigGfxInfo.DrawClr)+ " | ";
    Info += "F Color : ";
	Info += ApplicationManager::ColorString(FigGfxInfo.FillClr) + " | ";
}



