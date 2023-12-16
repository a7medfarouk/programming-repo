

#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point& P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

string Input::GetString(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D

	double D = 0;
	Point p;
	string s;
	//This function should make any needed validations on the entered text 
	// to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 …etc.).

	pO->PrintMessage("Please enter a value");

	//Read a double value from the user
	s = GetString(pO);
	bool k = IsValue(s);
	while (k == false) {
		pO->PrintMessage("Error! Please enter a valid value");
		s = GetString(pO);
		k = IsValue(s);
	}
	D = stod(s);
	return D;
}

string Input::GetVariable(Output* pO) const {
	string s;
	Point p;
	pO->PrintMessage("Please enter a variable name");
	s = GetString(pO);
	bool k = IsVariable(s);
	while (k == false) {
		pO->PrintMessage("Ërror! Please enter a valid variable name");
		s = GetString(pO);
		k = IsVariable(s);
	}
	return s;

}

string Input::GetArithOperator(Output* pO) const {
	pWind->FlushKeyQueue();
	char Key;
	string s;
	bool isCorrect = false;
	while (1) {
		pWind->WaitKeyPress(Key);
		if (s.size() == 0) {
			if (Key == '+' || Key == '-' || Key == '*' || Key == '/') {
				s.push_back(Key);
				isCorrect = true;
			}
			else if (Key == 27 || Key == 13) {
				continue;
			}
			else
			{
				pO->PrintMessage("Error! Enter a valid operator");
				isCorrect = false;
				s = "";
			}
		}
		else if (s.size() == 1) {
			if (Key != 27 && Key != 13)
			{
				s.push_back(Key);
			}

			if (s == "+=" || s == "-=" || s == "*=" || s == "/=") {
				isCorrect = true;
				break;
			}
			else if (Key == 27 || Key == 13) {
				isCorrect = true;
				break;
			}
			else
			{
				pO->PrintMessage("Error! Enter a valid operator");
				isCorrect = false;
				s = "";
			}

		}
	}
	if (isCorrect == true)
	{
		pO->PrintMessage(s);
	}
	return s;
}

string Input::GetCompOperator(Output* pO) const {
	pWind->FlushKeyQueue();
	char Key;
	string s;
	bool isCorrect = false;
	while (1) {
		pWind->WaitKeyPress(Key);
		if (s.size() == 0) {
			if (Key == '=' || Key == '>' || Key == '<' || Key == '!') {
				s.push_back(Key);
			}
			else if (Key == 27 || Key == 13) {
				continue;
			}
			else
			{
				pO->PrintMessage("Error! Enter a valid operator");
				isCorrect = false;
				s = "";
			}
		}
		else if (s.size() == 1) {
			if (Key != 27 && Key != 13)
			{
				s.push_back(Key);
			}

			if (s == "==" || s == "!=" || s == ">=" || s == "<=") {
				isCorrect = true;
				break;
			}
			else if (Key == 27 || Key == 13) {
				if (s == ">" || s == "<")
				{
					isCorrect = true;
					break;
				}
				else
				{
					pO->PrintMessage("Error! Enter a valid operator");
					isCorrect = false;
					s = "";
				}
			}
			else
			{
				pO->PrintMessage("Error! Enter a valid operator");
				isCorrect = false;
				s = "";
			}

		}
	}
	if (isCorrect == true)
	{
		pO->PrintMessage(s);
	}
	return s;
}

ActionType Input::GetUserAction() const
{
	//This function reads the position where the user clicks to determine the desired action

	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_START: return ADD_START;

			case ITM_END: return ADD_END;

			case ITM_VALUE_ASSIGN: return ADD_VALUE_ASSIGN;

			case ITM_VAR_ASSIGN: return ADD_VAR_ASSIGN;

			case ITM_OPER_ASSIGN: return ADD_OPER_ASSIGN;

			case ITM_COND: return ADD_CONDITION;

			case ITM_READ: return ADD_READ;

			case ITM_WRITE: return ADD_WRITE;

			case ITM_CONNECTOR: return ADD_CONNECTOR;

			case ITM_SELECT: return SELECT;

			case ITM_EDIT_STAT: return EDIT_STAT;

			case ITM_DELETE: return DEL;

			case ITM_COPY: return COPY;

			case ITM_CUT: return CUT;

			case ITM_PASTE: return PASTE;

			case ITM_SAVE: return SAVE;

			case ITM_LOAD: return LOAD;

			case ITM_SWITCH_SIM_MODE: return SWITCH_SIM_MODE;

			case ITM_EXIT: return EXIT;
			default: return DSN_TOOL;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItem = (x / UI.MenuItemWidth);
			switch (ClickedItem)
			{
			case ITM_VALIDATE: return VALIDATE;
			case ITM_RUN: return RUN;
			case ITM_END: return END;
			case ITM_SWITCH_DSN_MODE: return SWITCH_DSN_MODE;
			default: return SIM_TOOL;
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}


}


Input::~Input()
{
}
