#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
	string lastmsg; // last message printed on the status bar
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateShapesToolBar() const;
	void CreateColorToolBar()  const;
	void CreateStatusBar() const;	//create the status bar
	void RedrawStatusBar();    // Redraw status bar With Same Last Printed Message
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearToolBar() const;      //Clears the Tool Bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ResetColors(); //Reset the Colors to default values
	void setBuffering(bool);
	void updateBuffer();
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawSquare(Point P1, double L, GfxInfo SquGfxInfo, bool selected) const;	//Draw a Square
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a triangle
	void DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a circle
	void DrawHex(Point P, double L, GfxInfo HexaGfxInfo, bool selected) const; //Draw a hexagon
	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg , bool redraw = 0) ;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	static string ColorString(color C);
	static color StringColor(string C);



	~Output();
};

#endif