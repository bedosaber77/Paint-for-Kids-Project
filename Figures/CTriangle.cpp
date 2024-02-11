#include "CTriangle.h"
#include <fstream>
#include "../ApplicationManager.h"
using namespace std;
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{

	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3; 	//Calculating Center of Triangle
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	S = TRIANGLE;
	CalcSinAndCos(); // Calculating Sin and Cos of Corners
}

CTriangle::CTriangle(int id) :CFigure(id)
{
	S = TRIANGLE;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}


double area(Point A, Point B, Point C) // Fucntion To Calc The Area of a Triangle
{
	return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}


bool CTriangle::IsInclude(Point P) const
{
	//if P lies inside the triangle, then sum of areas to that point with Corners must be equal to Triangle Original Area.
	return ( area( Corner1, Corner2, Corner3) == area(P, Corner2, Corner3) + area(P, Corner1, Corner3) + area(Corner1, Corner2, P) );


}

void CTriangle::PrintInfo(Output* pOut)
{
	Info = "";
	addToInfo("Triangle | ");
	CFigure::PrintInfo(pOut);


	addToInfo("Center : (");
	addToInfo(to_string(Center.x) + " , " + to_string(Center.y) + ") ");


	addToInfo("Corner1 : (");
	addToInfo(to_string(Corner1.x) + " , " + to_string(Corner1.y) + ") ");
	addToInfo("Corner2 : (");
	addToInfo(to_string(Corner2.x) + " , " + to_string(Corner2.y) + ") ");;
	addToInfo("Corner3 : (");
	addToInfo(to_string(Corner3.x) + " , " + to_string(Corner3.y) + ") ");

	pOut->PrintMessage(Info);
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRI\t" << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t'
		<< Corner3.x << '\t' << Corner3.y << '\t' << Output::ColorString(FigGfxInfo.DrawClr)<<'\t';
	if (FigGfxInfo.isFilled) {
		OutFile << Output::ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		OutFile << "NO_FILL\n";
}

void CTriangle::Load(ifstream& Infile)
{
	string DrwClr, FillClr;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y>>Corner3.x>>Corner3.y>>DrwClr>>FillClr;
	ChngDrawClr(Output::StringColor(DrwClr));
	if (FillClr != "NO_FILL")
	{
		ChngFillClr(Output::StringColor(FillClr));
	}
	else
		FigGfxInfo.isFilled = false;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
}

Point CTriangle::GetCenter()
{

	return Center;

}

void CTriangle::Moveto(Point NewCenter)
{


	//Shifting Corners 
	Corner1.x += (NewCenter.x - Center.x);
	Corner1.y += (NewCenter.y - Center.y);

	Corner2.x += (NewCenter.x - Center.x);
	Corner2.y += (NewCenter.y - Center.y);

	Corner3.x += (NewCenter.x - Center.x);
	Corner3.y += (NewCenter.y - Center.y);
	
	//Updating Center
	Center = NewCenter;
	CalcSinAndCos(); // Updating Sin and Cos of Corners


}


void CTriangle::CalcSinAndCos()
{
	//Calculating Sin and Cos of Corners
	SinCorners[0] = (Corner1.y - Center.y) / sqrt(pow(Corner1.x - Center.x, 2) + pow(Corner1.y - Center.y, 2));
	SinCorners[1] = (Corner2.y - Center.y) / sqrt(pow(Corner2.x - Center.x, 2) + pow(Corner2.y - Center.y, 2));
	SinCorners[2] = (Corner3.y - Center.y) / sqrt(pow(Corner3.x - Center.x, 2) + pow(Corner3.y - Center.y, 2));
	CosCorners[0] = (Corner1.x - Center.x) / sqrt(pow(Corner1.x - Center.x, 2) + pow(Corner1.y - Center.y, 2));
	CosCorners[1] = (Corner2.x - Center.x) / sqrt(pow(Corner2.x - Center.x, 2) + pow(Corner2.y - Center.y, 2));
	CosCorners[2] = (Corner3.x - Center.x) / sqrt(pow(Corner3.x - Center.x, 2) + pow(Corner3.y - Center.y, 2));

}


void CTriangle::Resize(Point Cursor)
{
	// Calculating Shift Distance
	double ShiftDistance = sqrt(pow(Cursor.x - Center.x, 2) + pow(Cursor.y - Center.y, 2));
	// Shifting Corners
	Corner1.x = Center.x + ShiftDistance * CosCorners[0];
	Corner1.y = Center.y + ShiftDistance * SinCorners[0];
	Corner2.x = Center.x + ShiftDistance * CosCorners[1];
	Corner2.y = Center.y + ShiftDistance * SinCorners[1];
	Corner3.x = Center.x + ShiftDistance * CosCorners[2];
	Corner3.y = Center.y + ShiftDistance * SinCorners[2];



}

bool CTriangle::isOnCorner(Point p)
{
	//Checking if the point is on any of the Corners
	Point Corners[3];
	Corners[0] = Corner1;
	Corners[1] = Corner2;
	Corners[2] = Corner3;
	for (int i = 0; i < 3; i++)
	{
		if (Corners[i].x <= p.x + 8 && Corners[i].x >= p.x - 8 && Corners[i].y <= p.y + 8 && Corners[i].y >= p.y - 8)
		{
			return true;
		}
	}
	//Checking if the point is on any of the sides
	return false;
}
