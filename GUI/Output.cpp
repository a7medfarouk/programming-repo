#include "Output.h"

//wwwwwwwwwwwwwwwwwwwwwwwwwwwwww
//ay 7aga
//any commenttttttttt//do you copy//yes i dodddddddd

Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_START] = "images\\start1.jpg";
	//MenuItemImages[ITM_END] = "images\\start1.jpg";
	//MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Assign.jpg";
	//MenuItemImages[ITM_VAR_ASSIGN] = "images\\Assign.jpg";
	//MenuItemImages[ITM_OPER_ASSIGN] = "images\\Assign.jpg";
	//MenuItemImages[ITM_COND] = "images\\Condition.jpg";
	//MenuItemImages[ITM_READ] = "images\\read.jpg";
	//MenuItemImages[ITM_WRITE] = "images\\read.jpg";
	//MenuItemImages[ITM_CONNECTOR] = "images\\connector.jpg";
	//MenuItemImages[ITM_SELECT] = "images\\select icon.jpg";
	//MenuItemImages[ITM_EDIT_STAT] = "images\\editicon.jpg";
	////MenuItemImages[ITM_DELETE] = "images\\delete.jpg";
	//MenuItemImages[ITM_COPY] = "images\\copy.jpg";
	//MenuItemImages[ITM_CUT] = "images\\cut.jpg";
	//MenuItemImages[ITM_PASTE] = "images\\paste.jpg";
	//MenuItemImages[ITM_SAVE] = "images\\Save.jpg";
	////MenuItemImages[ITM_SWITCH_SIM_MODE] = "images\\switch.jpg";
	//MenuItemImages[ITM_EXIT] = "images\\Exit.jpg";




	//Draw menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);
}
void Output::Drawconnector(Point Left, int width, int height, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawLine(Left.x, Left.y, Left.x + width,Left.y);


}

void Output::drawcond(Point Left, int width, int height, string Text, bool Selected) 
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	int xarr[4];
	int yarr[4];
	//Draw the statement block rectangle
	xarr[0] = Left.x;
	yarr[0] = Left.y;
	xarr[1] = Left.x + (0.5 * width);
	yarr[1] = Left.y + (0.5 * height);
	xarr[2] = Left.x + width;
	yarr[2] = Left.y;
	xarr[3] = xarr[1];
	yarr[3] = Left.y - (0.5 * height);
	pWind->DrawPolygon(xarr, yarr, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(xarr[0]+35,Left.y-10, Text);
}

void Output::drawellipse(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}
void Output::drawread(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	int xarr2[4];	int yarr2[4];
	//Draw the statement block rectangle
	xarr2[0] = Left.x;
	yarr2[0] = Left.y;

	xarr2[1] = Left.x + width;
	yarr2[1] = Left.y;

	xarr2[2] = xarr2[1] - 30;
	yarr2[2] = Left.y + height;

	xarr2[3] = xarr2[2] - width;
	yarr2[3] = yarr2[2];
	pWind->DrawPolygon(xarr2, yarr2, 4);
	
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(xarr2[0]+(1/2*width), Left.y + (1/2*height), Text);
}
//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them
	
//TODO: Add DrawConnector function

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
