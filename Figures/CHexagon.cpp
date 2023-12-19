#include "CHexagon.h"
#include <cmath>
#include <fstream>
#include "../ApplicationManager.h"
using namespace std;
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
	L = 120;
}

CHexagon::CHexagon(int id):CFigure(id)
{
	L = 120;
}


void CHexagon::Draw(Output* pOut) const
{

	pOut->DrawHex(Center, L ,FigGfxInfo, Selected);
}


bool CHexagon::IsInclude(Point P) const
{
	// Source For Details :: http://www.playchilla.com/how-to-check-if-a-point-is-inside-a-hexagon

	double h = L * 0.86602540378; // sin (60) * SideLength;

	if (fabs(P.x - Center.x) > h || fabs(P.y - Center.y) > L ) return false;
	return  L  * h - L / 2 * fabs(P.x - Center.x) - h * fabs(P.y - Center.y) >= 0;
}

void CHexagon::PrintInfo(Output* pOut)
{
    CFigure::PrintInfo(pOut);
}

void CHexagon::Save(ofstream& OutFile) {
	OutFile << "HEXAGON\t" << ID<< '\t' << Center.x <<'\t' << Center.y << '\t' 
		<< ApplicationManager::ColorString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled) {
		OutFile << ApplicationManager::ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		OutFile << "NO_FILL\n";
}

void CHexagon::Load(ifstream& Infile)
{
	string DrwClr, FillClr;
	Infile >> Center.x >> Center.y >> DrwClr >> FillClr;
	ChngDrawClr(ApplicationManager::StringColor(DrwClr));
	if (FillClr != "NO_FILL")
	{
     ChngFillClr(ApplicationManager::StringColor(FillClr));
	}
	else
		FigGfxInfo.isFilled = false;
}
