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
	Info = "";
	double Radius = sqrt(pow(PointOnCircle.x - Center.x, 2) + pow(PointOnCircle.y - Center.y, 2));
	addToInfo("Circle | ");
	CFigure::PrintInfo(pOut);
	addToInfo("Center : (");
	addToInfo(to_string(Center.x) + " , " + to_string(Center.y) + ") ");
	addToInfo(" | Radius : " + to_string(Radius).substr(0, to_string(Radius).find('.') + 3)); // Controlling 2 Decimal Points
	pOut->PrintMessage(Info);
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRC\t" << ID << '\t' << Center.x << '\t' << Center.y << '\t' << PointOnCircle.x << '\t'
		<< PointOnCircle.y << '\t' << Output::ColorString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled) {
		OutFile << Output::ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		OutFile << "NO_FILL\n";
}

void CCircle::Load(ifstream& Infile)
{
	string DrwClr, FillClr;
	Infile >> Center.x >> Center.y >> PointOnCircle.x >> PointOnCircle.y>>DrwClr>>FillClr;
	ChngDrawClr(Output::StringColor(DrwClr));
	if (FillClr != "NO_FILL")
	{
		ChngFillClr(Output::StringColor(FillClr));
	}
	else
		FigGfxInfo.isFilled = false;
}

Point CCircle::GetCenter()
{
	return Center;
}

void CCircle::Moveto(Point NewCenter)
{


	//Updating Point On Circle


	PointOnCircle.x += (NewCenter.x - Center.x);
	PointOnCircle.y += (NewCenter.y - Center.y);

	//Updating Center

	Center = NewCenter;


}
