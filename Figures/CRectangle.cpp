#include "CRectangle.h"
#include <fstream>
#include "../ApplicationManager.h"
using namespace std;

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	S = RECTANGLE;
}

CRectangle::CRectangle(int id):CFigure(id)
{
	S = RECTANGLE;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CRectangle::IsInclude(Point P) const
{
	//Checking if the point is inside the rectangle
	return (P.y >= min(Corner1.y, Corner2.y) && P.y <= max(Corner1.y, Corner2.y)) &&
		   (P.x >= min(Corner1.x, Corner2.x) && P.x <= max(Corner1.x, Corner2.x));
}


void CRectangle::PrintInfo(Output* pOut)
{
	Info = "";
	addToInfo("Rectangle | ");
	CFigure::PrintInfo(pOut);


	addToInfo("Center : (");
	addToInfo(to_string(Center.x) + " , " + to_string(Center.y) + ") ");


	addToInfo("Corner1 : (");
	addToInfo(to_string(Corner1.x) + " , " + to_string(Corner1.y) + ") ");
	addToInfo("Corner2 : (");
	addToInfo(to_string(Corner2.x) + " , " + to_string(Corner2.y) + ") ");;

	pOut->PrintMessage(Info);
}

void CRectangle::Save(ofstream& outfile)
{
	outfile << "RECT\t" << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' 
		<< Corner2.y << '\t' << Output::ColorString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled) {
		outfile << Output::ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		outfile << "NO_FILL\n";
}

void CRectangle::Load(ifstream& Infile)
{
	string DrwClr, FillClr;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y>>DrwClr>>FillClr;
	ChngDrawClr(Output::StringColor(DrwClr));
	if (FillClr != "NO_FILL")
	{
		ChngFillClr(Output::StringColor(FillClr));
	}
	else
		FigGfxInfo.isFilled = false;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y= (Corner1.y + Corner2.y) / 2;
}

Point CRectangle::GetCenter()
{


	return Center;

}

void CRectangle::Moveto(Point NewCenter)
{

	//Shifting Corners 
	Corner1.x += (NewCenter.x - Center.x);
	Corner1.y += (NewCenter.y - Center.y);

	Corner2.x += (NewCenter.x - Center.x);
	Corner2.y += (NewCenter.y - Center.y);


	//Updating Center
	Center = NewCenter;


}

void CRectangle::Resize(Point Cursor)
{
	Corner1.x -= (Cursor.x - Corner2.x);
	Corner1.y -= (Cursor.y - Corner2.y);
	Corner2.x = Cursor.x;
	Corner2.y = Cursor.y;
}


bool CRectangle::isOnCorner(Point p)
{
	//Getting the Other 2 Corners of the Rectangle
	Point Corner3, Corner4;
	Corner3.x = Corner2.x;
	Corner3.y = Corner1.y;
	Corner4.x = Corner1.x;
	Corner4.y = Corner2.y;


	return (

		// Checking all 4 Corners


		(((p.x <= Corner1.x + 8) && (p.x >= Corner1.x - 8)) && ((p.y <= Corner1.y + 8) && (p.y >= Corner1.y - 8))) ||
		(((p.x <= Corner2.x + 8) && (p.x >= Corner2.x - 8)) && ((p.y <= Corner2.y + 8) && (p.y >= Corner2.y - 8))) ||
		(((p.x <= Corner3.x + 8) && (p.x >= Corner3.x - 8)) && ((p.y <= Corner3.y + 8) && (p.y >= Corner3.y - 8))) ||
		(((p.x <= Corner4.x + 8) && (p.x >= Corner4.x - 8)) && ((p.y <= Corner4.y + 8) && (p.y >= Corner4.y - 8)))



		);

}



