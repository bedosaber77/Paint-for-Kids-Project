#pragma once
#include "CFigure.h"
class CHexagon :
    public CFigure
{
private:
	Point Center;
	double L; // Side Length

public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	bool IsInclude(Point P) const;
	void PrintInfo(Output* pOut);

	virtual void Save(ofstream& OutFile);


};

