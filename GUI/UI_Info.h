#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_SHAPES,//Pick SHAPE mode
	MODE_COLORS,//Pick Color mode
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	ITM_SHAPES,
	ITM_COLORPICK,
	ITM_PLAYMODE,
	ITM_BORDER,
	ITM_FILL,//Note: Items are **(ordered)** here as they appear in menu
	
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ShapeMenuItem //The items of Shape menu
{
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,      //Circle item in menu
	ITM_SQU,       //Square item in menu
	ITM_TRI,       //Triangle item in menu
	ITM_HEX,       //Hexagone item in menu
	ITM_BACK,      //Back Button to main

    SHAPES_ITM_COUNT  //no. of Shape menu items ==> This should be the last line in this enum
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;     //Tool bar Color  
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif