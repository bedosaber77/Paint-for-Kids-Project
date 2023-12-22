#include "CCircle.h"
#include <fstream>
#include "../ApplicationManager.h"
using namespace std;

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
	PointOnCircle = P2;
	S = CIRCLE;
}

CCircle::CCircle(int id):CFigure(id)
{
}


void CCircle::Draw(Output* pOut) const
{

	pOut->DrawCircle(Center, PointOnCircle, FigGfxInfo, Selected);
}


bool CCircle::IsInclude(Point P) const
{
	return   sqrt(pow(P.x - Center.x, 2) + pow(P.y - Center.y, 2)) <=
		     sqrt(pow(PointOnCircle.x - Center.x, 2) + pow(PointOnCircle.y - Center.y, 2) );// Checking if Distance to the Center <= Radius


}

void CCircle::PrintInfo(Output* pOut)
{
	CFigure::PrintInfo(pOut);
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRC\t" << ID << '\t' << Center.x << '\t' << Center.y << '\t' << PointOnCircle.x << '\t'
		<< PointOnCircle.y << '\t' <<ApplicationManager :: ColorString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled) {
		OutFile << ApplicationManager :: ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		OutFile << "NO_FILL\n";
}

void CCircle::Load(ifstream& Infile)
{
	string DrwClr, FillClr;
	Infile >> Center.x >> Center.y >> PointOnCircle.x >> PointOnCircle.y>>DrwClr>>FillClr;
	ChngDrawClr(ApplicationManager::StringColor(DrwClr));
	if (FillClr != "NO_FILL")
	{
		ChngFillClr(ApplicationManager::StringColor(FillClr));
	}
	else
		FigGfxInfo.isFilled = false;
}
