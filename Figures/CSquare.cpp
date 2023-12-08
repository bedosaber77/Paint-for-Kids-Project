#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::IsInclude(Point P) const
{
	int SquareSideLength = 200; // want to make it more felxiable u know Anas Ibrahem

	if ( (P.y <= Center.y + SquareSideLength / 2 && P.y >= Center.y - SquareSideLength / 2) && 
		(P.x <= Center.x + SquareSideLength / 2 && P.x >= Center.x - SquareSideLength / 2) )
		return 1;

	else 
	return 0;
}
