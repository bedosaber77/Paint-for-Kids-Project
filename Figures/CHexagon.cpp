#include "CHexagon.h"
#include <cmath>
#include <fstream>
#include "../ApplicationManager.h"
using namespace std;
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
	L = 120; //Default length
	S = HEXAGON;

}

CHexagon::CHexagon(int id):CFigure(id)
{
	S = HEXAGON;
}


void CHexagon::Draw(Output* pOut) const
{

	pOut->DrawHex(Center, L ,FigGfxInfo, Selected);
}


bool CHexagon::IsInclude(Point P) const
{
	// Source For Details :: http://www.playchilla.com/how-to-check-if-a-point-is-inside-a-hexagon

	double h = L * 0.86602540378; // sin (60) * SideLength; 

	if (fabs(P.x - Center.x) > h || fabs(P.y - Center.y) > L ) return false; // Quick Rejection
	return  L  * h - L / 2 * fabs(P.x - Center.x) - h * fabs(P.y - Center.y) >= 0; // Final Check
}

void CHexagon::PrintInfo(Output* pOut)
{
	//Prints all figure info on the status bar
	Info = "";
	addToInfo("Hexagon | ");
    CFigure::PrintInfo(pOut);
	addToInfo("Center : (");
	addToInfo(to_string(Center.x) + " , " + to_string(Center.y) + ") ");
	addToInfo(" | Side Length : " + to_string(L).substr(0, to_string(L).find('.') + 3)); // Controlling 2 Decimal Points
	pOut->PrintMessage(Info);

}

void CHexagon::Save(ofstream& OutFile) {
	OutFile << "HEXAGON\t" << ID<< '\t' << Center.x <<'\t' << Center.y << '\t' << L << '\t'
		<< Output::ColorString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled) {
		OutFile << Output::ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		OutFile << "NO_FILL\n";
}

void CHexagon::Load(ifstream& Infile)
{
	string DrwClr, FillClr;
	Infile >> Center.x >> Center.y >> L >> DrwClr >> FillClr;
	ChngDrawClr(Output::StringColor(DrwClr));
	if (FillClr != "NO_FILL")
	{
     ChngFillClr(Output::StringColor(FillClr));
	}
	else
		FigGfxInfo.isFilled = false;
}

Point CHexagon::GetCenter()
{
	return Center;
}

void CHexagon::Moveto(Point NewCenter)
{
	//Updating Center
	Center = NewCenter;

}

void CHexagon::Resize(Point	Cursor)
{
	//Updating Side Length
	L = sqrt(pow(Cursor.x - Center.x, 2) + pow(Cursor.y - Center.y, 2));

}

bool CHexagon::isOnCorner(Point Cursor)

{
	const double PI = 3.14159265;
	Point Corner[6];
	//Calculating Corners
	for (int i = 0; i < 6; i++)
	{
		Corner[i].x = Center.x + L * sin(i * 60 * PI / 180);
		Corner[i].y = Center.y - L * cos(i * 60 * PI / 180);
	}

	//Checking if Cursor is on any of the Corners
	for (int i = 0; i < 6; i++)
	{

		if ( (Cursor.x <= Corner[i].x + 8 && Cursor.x >= Corner[i].x - 8 ) && (Cursor.y <= Corner[i].y + 8 && Cursor.y >= Corner[i].y - 8) )
			return true;

	}
	//If Cursor is not on any of the Corners
	return false;


}
