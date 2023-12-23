#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	static int id;
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	string Info;
	bool Hidden;
	/// Add more parameters if needed.

public:
	enum Shape {RECTANGLE,CIRCLE,TRIANGLE,HEXAGON,SQUARE};
	Shape S;

	CFigure(GfxInfo FigureGfxInfo);
	CFigure(int);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool IsInclude(Point) const; //make it pure Anas Ibrahem
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	color getDrawClr();
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color getFillClr();
	bool IsFilled();

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	color GetColor();//PICKANDHIDE
	Shape GetShape();
	virtual Point GetCenter()  = 0 ;
	virtual void  Moveto(Point) = 0;
	void addToInfo(string s);


	void SetHidden(bool);
	bool GetHidden();

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar  
};

#endif

