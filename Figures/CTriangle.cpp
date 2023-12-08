#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

bool CTriangle::IsInclude(Point P) const
{

    double detT = (Corner2.y - Corner3.y) * (Corner1.x - Corner3.x) + (Corner3.x - Corner2.x) * (Corner1.y - Corner3.y);

    double alpha = ((Corner2.y - Corner3.y) * (P.x - Corner3.x) + (Corner3.x - Corner2.x) * (P.y - Corner3.y)) / detT;
    double beta = ((Corner3.y - Corner1.y) * (P.x - Corner3.x) + (Corner1.x - Corner3.x) * (P.y - Corner3.y)) / detT;
    double gamma = 1.0 - alpha - beta;

    // Check if the point is inside the triangle
    return alpha >= 0.0 && beta >= 0.0 && gamma >= 0.0;;

}