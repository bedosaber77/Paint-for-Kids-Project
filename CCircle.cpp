#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	PointOnCircle = P2;
}


void CCircle::Draw(Output* pOut) const
{

	pOut->DrawCircle(Center, PointOnCircle, FigGfxInfo, Selected);
}