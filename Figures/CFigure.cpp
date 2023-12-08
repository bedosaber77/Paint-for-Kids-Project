#include "CFigure.h"



string ColorString(color C) {

	if (C == BLACK)    return "BLACK";
	if (C == GREEN)    return "GREEN";
	if (C == ORANGE)   return "ORANGE";
	if (C == YELLOW)   return "YELLOW";
	if (C == RED)      return "RED";
	if (C == BLUE)     return "BLUE";

}


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
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

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::PrintInfo(Output* pOut)
{
	string Info = "ID : ";
	Info += to_string(ID) + " | ";
	Info += "D Color : ";
	Info += ColorString(FigGfxInfo.DrawClr)+ " | ";
    Info += "F Color : ";
	Info += ColorString(FigGfxInfo.FillClr) + " | ";
	pOut->PrintMessage(Info);
}



