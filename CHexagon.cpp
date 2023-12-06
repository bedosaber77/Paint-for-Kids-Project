#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;

}


void CHexagon::Draw(Output* pOut) const
{

	pOut->DrawHex(Center, FigGfxInfo, Selected);
}