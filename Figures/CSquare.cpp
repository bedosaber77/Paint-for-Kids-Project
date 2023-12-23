#include "CSquare.h"
#include <fstream>
#include "../ApplicationManager.h"
using namespace std;
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	L = 180;
	S = SQUARE;
}

CSquare::CSquare(int id) :CFigure(id)
{
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
	Info = "";
	addToInfo("Square | ");
	CFigure::PrintInfo(pOut);
	addToInfo("Center : (");
	addToInfo(to_string(Center.x) + " , " + to_string(Center.y) + ") ");
	addToInfo(" | Side Length : " + to_string(L).substr(0, to_string(L).find('.') + 3)); // Controlling 2 Decimal Points
	pOut->PrintMessage(Info);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE\t" << ID << '\t' << Center.x << '\t' << Center.y << '\t'
		<< Output::ColorString(FigGfxInfo.DrawClr)<<'\t';
	if (FigGfxInfo.isFilled) {
		OutFile << Output::ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		OutFile << "NO_FILL\n";
}

void CSquare::Load(ifstream& Infile)
{
	string DrwClr, FillClr;
	Infile >> Center.x >> Center.y >> DrwClr >> FillClr;
	ChngDrawClr(Output::StringColor(DrwClr));
	if (FillClr != "NO_FILL")
	{
		ChngFillClr(Output::StringColor(FillClr));
	}
	else
		FigGfxInfo.isFilled = false;
}

Point CSquare::GetCenter()
{
	return Center;
}

void CSquare::Moveto(Point NewCenter)
{



	//Updating Center
	Center = NewCenter;


}

void CSquare::Resize(Point Cursor)
{
	double x, y;
	x = pow((Cursor.x - Center.x), 2);
	y = pow((Cursor.y - Center.y), 2);
	L = sqrt(x + y)*2/pow(2,0.5);
}

bool CSquare::isOnCorner(Point p)
{
	return (((Center.x + L / 2 <= p.x + 8 && Center.x + L / 2 >= p.x - 8) && ((Center.y + L / 2 <= p.y + 8 && Center.y + L / 2 >= p.y - 8)))||
		((Center.x - L / 2 <= p.x + 8 && Center.x - L / 2 >= p.x - 8) && ((Center.y - L / 2 <= p.y + 8 && Center.y - L / 2 >= p.y - 8))));
}


