#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Center;

public:
	CRectangle(int);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsInclude(Point P) const;
	void PrintInfo(Output* pOut);
	virtual void Save(ofstream& outfile);
	virtual void Load(ifstream& Infile);
	Point GetCenter();
	void  Moveto(Point NewCenter);

};

#endif