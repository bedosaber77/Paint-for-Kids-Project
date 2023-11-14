#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SHAPES: return SHAPES_PICK;
			case ITM_PLAYMODE: return TO_PLAY;
			case ITM_BORDER: return BORDER_COLOR_PICK;
			case ITM_FILL:return FILL_COLOR_PICK;
			case ITM_SAVE:return SAVE_GRAPH;
			case ITM_LOAD:return LOAD;
			case ITM_UNDO:return UNDO;
			case ITM_REDO:return REDO;
			case ITM_STARTREC:return START_REC;
			case ITM_STOPREC:return STOP_REC;
			case ITM_PLAYREC:return PLAY_REC;
			case ITM_DELETE:return ERASE;
			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY) //Gui is in Adding Figure Phase
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SHAPEPICK: return SHAPE_PLAY_PICK;
			case ITM_COLOREDSHAPEPICK: return COLORED_SHAPE_PLAY_PICK;
			case ITM_COLORPICK: return COLOR_PLAY_PICK;
			case ITM_BACK2:return TO_DRAW;
			case ITM_RESTART:return RESTART_PLAY;


			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}

	else if (UI.InterfaceMode == MODE_SHAPES) //Gui is in Adding Figure Phase
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_SQU: return DRAW_SQU;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEX: return DRAW_HEX;
			case ITM_BACK:return TO_DRAW;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}
	else if (UI.InterfaceMode == MODE_COLORS) //Gui is in Color Selection Phase
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case COLOR_BLACK: return PICK_BLACK;
			case COLOR_BLUE: return PICK_BLUE;
			case COLOR_GREEN: return PICK_GREEN;
			case COLOR_ORANGE: return PICK_ORANGE;
			case COLOR_YELLOW: return PICK_YELLOW;
			case COLOR_RED:return PICK_RED;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}


	//else	//GUI is in PLAY mode
	//{
	//	///TODO:
	//	//perform checks similar to Draw mode checks above
	//	//and return the correspoding action
	//	return TO_PLAY;	//just for now. This should be updated
	//}	

}
/////////////////////////////////
	
Input::~Input()
{
}
