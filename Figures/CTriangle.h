#pragma once
#include "CFigure.h"
class CTriangle :
    public CFigure
{

private:
	Point Corner1 ,Corner2 ,Corner3 ,Center;
	double SinCorners[3]; // Sins Of Corners used in Resizing
	double CosCorners[3]; // Coss Of Corners used in Resizing


public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle(int);
	virtual void Draw(Output* pOut) const;

	double CalcArea(Point A, Point B, Point C);

	bool IsInclude(Point P) const;
	void PrintInfo(Output* pOut);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	Point GetCenter();
	void  Moveto(Point NewCenter);

	void CalcSinAndCos(); // Calculate Sins And Coss For Resizing	
	void Resize(Point Cursor);
	bool isOnCorner(Point p);


};

