#include "CSquare.h"
#include <fstream>
#include "../ApplicationManager.h"
using namespace std;
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	L = 180;
}


void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, L, FigGfxInfo, Selected);
}

bool CSquare::IsInclude(Point P) const
{
	return (P.y <= Center.y + L / 2 && P.y >= Center.y - L / 2) &&
		   (P.x <= Center.x + L / 2 && P.x >= Center.x - L / 2);
}

void CSquare::PrintInfo(Output* pOut)
{
	CFigure::PrintInfo(pOut);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE\t" << ID << '\t' << Center.x << '\t' << Center.y << '\t'
		<< ApplicationManager::ColorString(FigGfxInfo.DrawClr)<<'\t';
	if (FigGfxInfo.isFilled) {
		OutFile << ApplicationManager::ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		OutFile << "NO_FILL\n";
}
