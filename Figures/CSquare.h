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
	CSquare(int);
	virtual void Draw(Output* pOut) const;
	bool IsInclude(Point) const;
	void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

