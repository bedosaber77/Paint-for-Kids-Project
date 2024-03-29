#include "Output.h"
#include <cmath>
#include <string>

Output::Output() : lastmsg("")
{
	//Initialize user interface parameters (Defualts)
	UI.InterfaceMode = MODE_DRAW;
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;
	UI.StatusBarHeight = 40;
	UI.ToolBarHeight = 60;
	UI.MenuItemWidth = 60;
	UI.isFilled = false; //Defualt Not Filled
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = WHITESMOKE;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = WHITESMOKE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = PURPLE;
	UI.ToolBarColor = WHITE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.isSoundON = true;    //Default Sound is ON
	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Team 11");
	
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
void Output::RedrawStatusBar() 
{
	CreateStatusBar();
	PrintMessage(lastmsg , true); //Redraw Last Message //Update Interface Case
	
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
	string MenuItemImages[DRAW_ITM_COUNT]; //Icons of Draw Main Menu from its Folder
	MenuItemImages[ITM_SHAPES] = "images\\MenuItems\\Menu_Shapes.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Menu_Playmode.jpg";
	MenuItemImages[ITM_BORDER] = "images\\MenuItems\\Menu_Border.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_Resize.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_MOVE_BY_DRAGGING] = "images\\MenuItems\\Menu_Move_By_Dragging.jpg";


	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\Menu_PlayRecord.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\Menu_StopRecord.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\Menu_StartRecord.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_SOUND] = "images\\MenuItems\\sound.jpg";
	MenuItemImages[ITM_MUTE] = "images\\MenuItems\\mute.jpg";
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
	UI.InterfaceMode = MODE_PLAY; //Creating Tool bar For Play Mode
	ClearToolBar();
	// You Can reoder them in UI_Info.h ==> enum PlayMenuItem

	string ShapePlayModeImages[PLAY_ITM_COUNT]; //Icons of PlayMode objects from its Folder
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
	UI.InterfaceMode = MODE_SHAPES; //Creating Tool bar For Shapes
	ClearToolBar();
	// You Can reoder them in UI_Info.h ==> enum ShapeMenuItem

	string ShapeMenuItemImages[SHAPES_ITM_COUNT]; //Icons of Shapes from its Folder
	ShapeMenuItemImages[ITM_RECT] = "images\\Shapes\\Menu_Rect.jpg";
	ShapeMenuItemImages[ITM_CIRC] = "images\\Shapes\\Menu_Circ.jpg";
	ShapeMenuItemImages[ITM_SQU] = "images\\Shapes\\Menu_Squ.jpg";
	ShapeMenuItemImages[ITM_TRI] = "images\\Shapes\\Menu_Tri.jpg";
	ShapeMenuItemImages[ITM_HEX] = "images\\Shapes\\Menu_Hex.jpg";
	ShapeMenuItemImages[ITM_BACK] = "images\\Shapes\\Menu_Back.jpg";



	//Draw menu item one image at a time
	for (int i = 0; i < SHAPES_ITM_COUNT; i++)
		pWind->DrawImage(ShapeMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(PURPLE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::CreateColorToolBar() const
{
	UI.InterfaceMode = MODE_COLORS;//Creating Tool bar For Colors
	ClearToolBar();

	// You Can reoder them in UI_Info.h ==> enum ColorMenuItem
	string ColorMenuItemImages[COLOR_ITM_COUNT]; //Icons of Colors from its Folder
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
void Output::ResetColors()
{
	UI.isFilled = false; //Defualt Not Filled
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = GREEN;	//Filling color

}
void Output::setBuffering(bool x)
{
	pWind->SetBuffering(x);
}
void Output::updateBuffer()
{
	pWind->UpdateBuffer();
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg, bool redraw)	//Prints a message on status bar
{
	if  (lastmsg != msg || redraw)  // To Avoid Redrawing The Same Message In Loops Excpet If Redraw Flag Is True (Update Interface)
	{
		ClearStatusBar();	//First clear the status bar
		pWind->SetPen(UI.MsgColor, 50);
		pWind->SetFont(20, BOLD, BY_NAME, "Arial");
		pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1), msg);
		lastmsg = msg; //Save Last Message}
	}
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

string Output::ColorString(color C)
{
	if (C == BLACK)    return "BLACK";
	if (C == GREEN)    return "GREEN";
	if (C == ORANGE)   return "ORANGE";
	if (C == YELLOW)   return "YELLOW";
	if (C == RED)      return "RED";
	if (C == BLUE)     return "BLUE";
	if (C == WHITESMOKE) return "TRANSPERNT";
}

color Output::StringColor(string C)
{
	if (C == "BLACK")    return BLACK;
	if (C == "GREEN")    return GREEN;
	if (C == "ORANGE")   return ORANGE;
	if (C == "YELLOW")   return YELLOW;
	if (C == "RED")      return RED;
	if (C == "BLUE")     return BLUE;
	if (C == "TRANSPERNT") return WHITESMOKE;
}

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
	
	pWind->SetPen(DrawingClr,UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

//2.Draw Square:

//Draw Square Function Special Case Of Draw Rect
void Output::DrawSquare(Point P1, double L, GfxInfo SquGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (SquGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point P2;
	P2.x = P1.x + L / 2;
	P2.y = P1.y + L / 2;
	P1.x = P1.x - L / 2;
	P1.y = P1.y - L / 2;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

//3.Draw Triangle:

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth );
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

//4.Draw Circle:


void Output::DrawCircle(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth );
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2)), style);

}

//5.Drawing Hexagon:

void Output::DrawHex(Point P, double L, GfxInfo HexaGfxInfo, bool selected) const 
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;  //Figure should be drawn highlighted or not
	else
		DrawingClr = HexaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth );
	drawstyle style;
	if (HexaGfxInfo.isFilled) //Figure should be drawn Filled Or not
	{
		style = FILLED;
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else
		style = FRAME;
	const int NumVertices = 6;
	const double angle = 60 * 3.14159265 / 180; //60 degree and convert it to radian
	int arrX[NumVertices]; //array of x-coordinates for each vertix
	int arrY[NumVertices]; //array of y-coordinates for each vertix
	for (int i = 0; i < NumVertices; i++) {
		arrX[i] = P.x + (L * sin( angle * i));
		arrY[i] = P.y - (L * cos( angle * i));
	}
	pWind->DrawPolygon(arrX, arrY, NumVertices, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	//Destrucor Delete Allocated Memory
	delete pWind;
}

