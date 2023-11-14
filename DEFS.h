#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	
	///TODO: Add the other action types of the two modes
	SHAPES_PICK,
	DRAW_CIRC,      //DRAW Circle
	DRAW_SQU,		//Draw Square
	DRAW_TRI,		//Draw Triangle
	DRAW_HEX,		//Draw Hexagaon
	
	BORDER_COLOR_PICK,   //Color Pick Menu
	FILL_COLOR_PICK,


	/////////////////////////////
	
	
	PICK_BLACK,		//Pick Black in Color Menu Items
	PICK_BLUE,		//Pick Blue in Color Menu Items
	PICK_GREEN,		//Pick Green in Color Menu Items
	PICK_ORANGE,	//Pick Orange in Color Menu Items
	PICK_YELLOW,	//Pick Yellow in Color Menu Items
	PICK_RED,		//Pick Red in Color Menu Items

	RESTART_PLAY,
	SHAPE_PLAY_PICK,
	COLORED_SHAPE_PLAY_PICK,
	COLOR_PLAY_PICK,

	SAVE_GRAPH,
	LOAD,
	UNDO,
	REDO,
	START_REC,
	STOP_REC,
	PLAY_REC,
	ERASE,



};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif