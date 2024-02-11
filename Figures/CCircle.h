#pragma once
#include "CFigure.h"
class CCircle :
    public CFigure
{


private:
	Point Center;
	Point PointOnCircle;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle(int);
	virtual void Draw(Output* pOut) const;

	bool IsInclude(Point P) const;
	void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	Point GetCenter();
	void  Moveto(Point NewCenter) ;
	
	void Resize(Point Cursor);
	bool isOnCorner(Point p);


};

