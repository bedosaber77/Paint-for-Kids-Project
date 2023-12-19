#include "CRectangle.h"
#include <fstream>
#include "../ApplicationManager.h"
using namespace std;

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

CRectangle::CRectangle(int id):CFigure(id)
{
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CRectangle::IsInclude(Point P) const
{

	return (P.y >= min(Corner1.y, Corner2.y) && P.y <= max(Corner1.y, Corner2.y)) &&
		   (P.x >= min(Corner1.x, Corner2.x) && P.x <= max(Corner1.x, Corner2.x));
}


void CRectangle::PrintInfo(Output* pOut)
{
	CFigure::PrintInfo(pOut);
}

void CRectangle::Save(ofstream& outfile)
{
	outfile << "RECT\t" << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' 
		<< Corner2.y << '\t' << ApplicationManager::ColorString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled) {
		outfile << ApplicationManager::ColorString(FigGfxInfo.FillClr) << '\n';
	}
	else
		outfile << "NO_FILL\n";
}

void CRectangle::Load(ifstream& Infile)
{
	string DrwClr, FillClr;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y>>DrwClr>>FillClr;
	ChngDrawClr(ApplicationManager::StringColor(DrwClr));
	if (FillClr != "NO_FILL")
	{
		ChngFillClr(ApplicationManager::StringColor(FillClr));
	}
	else
		FigGfxInfo.isFilled = false;
}
