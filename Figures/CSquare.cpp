#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
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
	CFigure::PrintInfo(pOut);
}
