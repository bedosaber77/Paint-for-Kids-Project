#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
	PointOnCircle = P2;
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