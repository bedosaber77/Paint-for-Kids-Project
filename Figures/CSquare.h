#pragma once
#include "CFigure.h"
class CSquare :
    public CFigure
{

private:
	Point Center;
	double L; //Side Length
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsInclude(Point) const;
	void PrintInfo(Output* pOut);
};

