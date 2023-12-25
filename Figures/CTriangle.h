#pragma once
#include "CFigure.h"
class CTriangle :
    public CFigure
{

private:
	Point Corner1 ,Corner2 ,Corner3 ,Center;
	int CornerNumResize;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle(int);
	virtual void Draw(Output* pOut) const;

	bool IsInclude(Point P) const;
	void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	Point GetCenter();
	void  Moveto(Point NewCenter);
	
	void Resize(Point Cursor);
	bool isOnCorner(Point p);


};

