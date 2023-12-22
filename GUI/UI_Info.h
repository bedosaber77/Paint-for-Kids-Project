#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	
	MODE_SHAPES,//Pick SHAPE mode
	MODE_COLORS,//Pick Color mode
	test
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	ITM_SHAPES,

	ITM_PLAYMODE,
	ITM_BORDER,
	ITM_FILL,//Note: Items are **(ordered)** here as they appear in menu
	ITM_SELECT,
	ITM_MOVE,
	ITM_RESIZE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_UNDO,
	ITM_REDO,
	ITM_STARTREC,
	ITM_STOPREC,
	ITM_PLAYREC,
	ITM_CLEARALL,
	ITM_DELETE,
	ITM_SOUND,
	ITM_MUTE,
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
enum ColorMenuItem
{
	COLOR_BLACK,    //Color Black in color menu
	COLOR_BLUE,		//Color Blue in color menu
	COLOR_GREEN,	//Color Green in color menu
	COLOR_ORANGE,	//Color Orange in color menu
	COLOR_YELLOW,	//Color Yellow in color menu
	COLOR_RED,	    //Color Red in color menu

	COLOR_ITM_COUNT		//no. of Color menu items ==>> This should be the last line in this enum
};
enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names her
	ITM_SHAPEPICK,
	ITM_COLORPICK,
	ITM_COLOREDSHAPEPICK,
	ITM_RESTART,
	ITM_BACK2, //Back Button to drawmode
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
	
	bool isSoundON;             //Sound 
	bool isFilled;          //Is filled Defualt
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