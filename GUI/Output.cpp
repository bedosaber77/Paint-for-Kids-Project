#include "Output.h"
#include <cmath>


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 40;
	UI.ToolBarHeight = 60;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = PURPLE;
	UI.ToolBarColor = WHITE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SHAPES] = "images\\MenuItems\\Menu_Shapes.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Menu_Playmode.jpg";
	MenuItemImages[ITM_BORDER] = "images\\MenuItems\\Menu_Border.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\Menu_PlayRecord.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\Menu_StopRecord.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\Menu_StartRecord.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(PURPLE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	ClearToolBar();

	string ShapePlayModeImages[PLAY_ITM_COUNT];
	ShapePlayModeImages[ITM_COLORPICK] = "images\\PlayMode\\PickColor.jpg";
	ShapePlayModeImages[ITM_SHAPEPICK] = "images\\PlayMode\\PickShape.jpg";
	ShapePlayModeImages[ITM_COLOREDSHAPEPICK] = "images\\PlayMode\\PickColoredShape.jpg";
	ShapePlayModeImages[ITM_RESTART] = "images\\PlayMode\\Restart.jpg";
	ShapePlayModeImages[ITM_BACK2] = "images\\PlayMode\\Menu_Back.jpg";




	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(ShapePlayModeImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(PURPLE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);






	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateShapesToolBar() const
{
	UI.InterfaceMode = MODE_SHAPES;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	ClearToolBar();
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum ShapesMenuItem
	string ShapeMenuItemImages[SHAPES_ITM_COUNT];
	ShapeMenuItemImages[ITM_RECT] = "images\\Shapes\\Menu_Rect.jpg";
	ShapeMenuItemImages[ITM_CIRC] = "images\\Shapes\\Menu_Circ.jpg";
	ShapeMenuItemImages[ITM_SQU] = "images\\Shapes\\Menu_Squ.jpg";
	ShapeMenuItemImages[ITM_TRI] = "images\\Shapes\\Menu_Tri.jpg";
	ShapeMenuItemImages[ITM_HEX] = "images\\Shapes\\Menu_Hex.jpg";
	ShapeMenuItemImages[ITM_BACK] = "images\\Shapes\\Menu_Back.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < SHAPES_ITM_COUNT; i++)
		pWind->DrawImage(ShapeMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(PURPLE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::CreateColorToolBar() const
{
	UI.InterfaceMode = MODE_COLORS;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	ClearToolBar();
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum ColorMenuItem
	string ColorMenuItemImages[COLOR_ITM_COUNT];
	ColorMenuItemImages[COLOR_BLACK] = "images\\Colors\\Color_Black.jpg";
	ColorMenuItemImages[COLOR_BLUE] = "images\\Colors\\Color_Blue.jpg";
	ColorMenuItemImages[COLOR_GREEN] = "images\\Colors\\Color_Green.jpg";
	ColorMenuItemImages[COLOR_ORANGE] = "images\\Colors\\Color_Orange.jpg";
	ColorMenuItemImages[COLOR_YELLOW] = "images\\Colors\\Color_Yellow.jpg";
	ColorMenuItemImages[COLOR_RED] = "images\\Colors\\Color_Red.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < SHAPES_ITM_COUNT; i++)
		pWind->DrawImage(ColorMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(PURPLE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}


/////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

//1.Draw Rectangle:

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	ClearToolBar();
	CreateDrawToolBar();
	
}

//2.Draw Square:

void Output::DrawSquare(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point P2;
	P2.x = P1.x + 150;
	P2.y = P1.y + 150;
	P1.x = P1.x - 75;
	P1.y = P1.y - 75;
	

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	ClearToolBar();
	CreateDrawToolBar();

}

//3.Draw Triangle:

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	ClearToolBar();
	CreateDrawToolBar();
}

//4.Draw Circle:

void Output::DrawCircle(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, 150, style);
	ClearToolBar();
	CreateDrawToolBar();
}

//5.Drawing Hexagon:

void Output::DrawHex(Point P, GfxInfo HexaGfxInfo, bool selected) const 
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;  //Figure should be drawn highlighted
	else
		DrawingClr = HexaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else
		style = FRAME;
	const int NumVertices = 6;
	const double angle = 60 * 3.14159265 / 180; //60 degree and convert it to radian
	int L = 150; //set Length for the Figure
	int arrX[NumVertices]; //array of x-coordinates for each vertix
	int arrY[NumVertices]; //array of y-coordinates for each vertix
	for (int i = 0; i < NumVertices; i++) {
		arrX[i] = P.x + (L * sin( angle * i));
		arrY[i] = P.y - (L * cos( angle * i));
	}
	pWind->DrawPolygon(arrX, arrY, NumVertices, style);
	ClearToolBar();
	CreateDrawToolBar();
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

