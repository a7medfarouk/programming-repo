#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();	

	window* CreateWind(int, int, int , int);
	Input* CreateInput(); //Creates a pointer to the Input object	

	void CreateStatusBar(); //Creates status bar

	//TODO: Complete the following 2 functions
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar(); //Tool bar of the simulation mode

	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearOutputBar(); //Clears the Output bar
	void cleartoolbar();   //clears the tool bar (design or simulation)
	
	void PrintMessage(string msg);	//Prints a message on Status bar
	void DrawString(const int, const int, const string);  //Writes a string in the specified location

	// -- Statements Drawing Functions
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected=false);//drawing the rectangle (assignment)
	void Drawconnector(Point Left, int width, int height, bool Selected = false);//drawing the connector.
	void drawcond(Point Left, int width, int height, string Text, bool Selected=false);//drawing the rhombus(conditional)
	void drawellipse(Point Left, int width, int height, string Text, bool Selected = false);//draws the ellipse(start and end statements
	void drawread(Point Left, int width, int height, string Text, bool Selected=false);//draws the parallelogram(read and write
	
	
	~Output();
};

#endif