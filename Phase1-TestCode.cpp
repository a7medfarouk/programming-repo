
#include "HelperFn.h"
#include "GUI\Input.h"
#include "GUI\Output.h"


//This is a test code to test the Input and Output classes

int main()
{
	//int n;
	Point P;
	Point p2;
	Point p3;
	Point p4;
	//Point* no2ta = new Point[n];

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 0:	Testing the helper functions
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST0: Testing the helper functions");
	pIn->GetPointClicked(P);	//Wait for any click


	////////////
	//TODO: Add code here to 
	// 1- Read a (string) from the user --> just call the already impemented Input::GetString(...) fn
	// 2- Pass this string to IsValue(...) helper function 
	// 3- Print a message indicating its output (whether it's a value or not)
	// 4- -- REPEAT the same previous 3 steps to test: IsVariable(...) helper function
	// 5- -- REPEAT the same first 3 steps to test: ValueORVariable(...) helper function
	////////////
	pOut->PrintMessage("TEST0: Testing the helper functions");
	string Value = pIn->GetString(pOut);
	if (IsValue(Value)) pOut->PrintMessage("Is a value");
	else pOut->PrintMessage("Is not a value");
	pIn->GetPointClicked(P);

	pOut->PrintMessage("TEST1: Testing the helper functions");
	string Variable = pIn->GetString(pOut);
	if (IsVariable(Variable)) pOut->PrintMessage("Is a variable");
	else pOut->PrintMessage("Is not a variable");
	pIn->GetPointClicked(P);

	pOut->PrintMessage("TEST2: Testing the helper functions");
	string input = pIn->GetString(pOut);
	if (ValueOrVariable(input) == VALUE_OP) pOut->PrintMessage("Is a value");
	else if (ValueOrVariable(input) == VARIABLE_OP) pOut->PrintMessage("Is a variable");
	else pOut->PrintMessage("InValid");
	pIn->GetPointClicked(P);	//Wait for any click

	//Starting the input and output classes test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(P);	//Wait for any click
	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area, the output bar and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Statements with all possible states:
	//			Normal, highlighted, empty, filled with code
	//			Also drawing connectors
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any statement in any status, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	/// 2.1- Assignment statement test
	//Drawing assignment statements in all posible states
	
	pOut->PrintMessage("Drawing Simple Assignment statements in ALL STATES, Click to continue");
	
	//Drawing (normal) (empty) assignment statement --> STATE 1
	P.x = 100;	P.y = 100;
	pOut->DrawAssign(P,UI.ASSGN_WDTH, UI.ASSGN_HI, " = ");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	P.x = 300;	P.y = 100;
	pOut->DrawAssign(P,UI.ASSGN_WDTH, UI.ASSGN_HI, " = ", true);

	//Drawing a resized empty assignment statement
	P.x = 100;	P.y = 200;
	pOut->DrawAssign(P,80, UI.ASSGN_HI, " = ");

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	P.x = 100;	P.y = 300;
	pOut->DrawAssign(P,UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	P.x = 300;	P.y = 300;
	pOut->DrawAssign(P,UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000", true);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///2.2- Variable assignment & single operator assignment
	pOut->PrintMessage("Drawing other Assignment statements in ALL STATES, Click to continue");

	P.x = 100;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " X = Y");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	P.x = 300;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " X = Y ", true);

	//Drawing a resized empty assignment statement
	P.x = 100;	P.y = 200;
	pOut->DrawAssign(P, 80, UI.ASSGN_HI, "");
	P.x = 300;	P.y = 200;
	pOut->DrawAssign(P, 80, UI.ASSGN_HI, "",true);

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	P.x = 100;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	P.x = 300;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ", true);
	//Note: for other type of assignment, you can use the same draw assignment function but passing a different text

	
	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Conditional statement test
	//Drawing Conditional statements in all posible states
	pOut->PrintMessage("Drawing Conditional Statement in ALL STATES, Click to continue");
	P.x = 200; P.y = 150;
	pOut->drawcond(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "X==10",true);
	P.x = 400; P.y =150 ;
	pOut->drawcond(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "X==10");
	// DRAWING RESIZED EMPTY COND STATEMENTS//
	P.x = 200; P.y = 400;
	pOut->drawcond(P, 80, UI.ASSGN_HI, "", true);
	P.x = 400; P.y = 400;
	pOut->drawcond(P, 80, UI.ASSGN_HI, "");

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();
	
	//DRAWING DIFFERENT  ONDITIONAL STATEMENTS IN ALL STATES//
	pOut->PrintMessage("Drawing Conditional Statement in ALL STATES, Click to continue");
	P.x = 200; P.y = 150;
	pOut->drawcond(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Y>=10", true);
	P.x = 400; P.y = 150;
	pOut->drawcond(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Y>=10");
	// DRAWING RESIZED NORMAL AND HIGHLIGHTED EMPTY COND STATEMENTS//
	P.x = 200; P.y = 400;
	pOut->drawcond(P, 80, UI.ASSGN_HI, "", true);
	P.x = 400; P.y = 400;	Point P;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	pOut->PrintMessage("TEST0: Testing the input functions");
	double value = pIn->GetValue(pOut);
	pOut->PrintMessage("The value " + to_string(value));
	pIn->GetPointClicked(P);

	pOut->PrintMessage("TEST1: Testing the input functions");
	string variable = pIn->GetVariable(pOut);
	pOut->PrintMessage("The variable "+ variable);
	pIn->GetPointClicked(P);

	pOut->PrintMessage("TEST2: Testing the input functions");
	string arthOperator = pIn->GetArithOperator(pOut);
	pOut->PrintMessage("The arthimaticOperator " + arthOperator);
	pIn->GetPointClicked(P);

	pOut->PrintMessage("TEST3: Testing the input functions");
	string compOperator = pIn->GetCompOperator(pOut);
	pOut->PrintMessage("The compOperator " + compOperator);
	pIn->GetPointClicked(P);

	/*pOut->PrintMessage("TEST4: Testing the input function ");
	ActionType getuseraction = pIn->GetUserAction();
	pOut->PrintMessage("The GetUserAction " + getuseraction);
	pIn->GetPointClicked(P);*/

	pOut->drawcond(P, 80, UI.ASSGN_HI, "");


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Read statement test
	//Drawing Read statements in all posible states
	pOut->PrintMessage("Drawing Read Statement in ALL STATES, Click to continue");
	P.x = 200; P.y = 150;
	pOut->drawread(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "READ");
	//DRAWING NORMAL RESIZED EMPTY STATEMENTS//
	P.x = 400; P.y = 150;
	pOut->drawread(P, 100, UI.ASSGN_HI,"");

	P.x = 200; P.y = 400;
	pOut->drawread(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "READ", true);
	//DRAWING HIGHLIGHTED RESIZED EMPTY STATEMENTS//
	P.x = 400; P.y = 400;
	pOut->drawread(P, 100, UI.ASSGN_HI, "", true);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.5- Write statement test
	//Drawing Write statements in all posible states
	pOut->PrintMessage("Drawing Write Statement in ALL STATES, Click to continue");

	P.x = 200; P.y = 150;
	pOut->drawread(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "PRINT");
	//DRAWING RESIZED EMPTY NORMAL STATEMENTS//
	P.x = 400; P.y = 150;
	pOut->drawread(P, 100, UI.ASSGN_HI, "");

	P.x = 200; P.y = 400;
	pOut->drawread(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "PRINT", true);
	//DRAWING RESIZED EMPTY HIGHLIGHTED STATEMENTS//
	P.x = 400; P.y = 400;
	pOut->drawread(P, 100, UI.ASSGN_HI, "", true);
	

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.6- Start & End statements test
	//Drawing Start & End statements in all posible states
	pOut->PrintMessage("Drawing Start & End Statements in ALL STATES, Click to continue");
	//DRAWING NORMAL START AND END STATEMENTS//
	P.x = 100; P.y = 200;
	pOut->drawellipse(P, UI.ASSGN_WDTH, UI.ASSGN_HI,"START");
	P.x = 300; P.y = 200;
	pOut->drawellipse(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "END");
	//DRAWING RESIZED EMPTY STATEMENTS//
	P.x = 100; P.y = 300;
	pOut->drawellipse(P, 100, UI.ASSGN_HI, "",true);
	P.x = 300; P.y = 300;
	pOut->drawellipse(P, 100, UI.ASSGN_HI, "");
	//DRAWING HIGHLIGHTED START AND END STATEMENTS//
	P.x = 100; P.y = 400;
	pOut->drawellipse(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "START",true);
	P.x = 300; P.y =400;
	pOut->drawellipse(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "END",true);




	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.7- Connector test
	//Drawing Connector in all posible states
	pOut->PrintMessage("Drawing Connector in Normal and Highlighted STATES, Click to continue");
	P.x = 300;	P.y = 200;
	p2.x = 200; p2.y = 300;
	pOut->Drawconnector(P,p2);

	P.x = 400;	P.y = 200;
	p2.x = 500; p2.y = 300;
	pOut->Drawconnector(P, p2,true);

	P.x = 600;	P.y = 200;
	p2.x = 700; p2.y = 200;
	pOut->Drawconnector(P, p2);

	P.x =600 ;	P.y = 300 ;
	p2.x = 700; p2.y = 300;
	pOut->Drawconnector(P, p2, true);

	P.x = 300;	P.y = 400;
	p2.x = 500; p2.y = 400;
	p3.x = P.x + UI.ASSGN_WDTH; p3.y = P.y + 20;
	p4.x = p2.x; p4.y = p2.y + 20;
	pOut->drawellipse(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "START");
	pOut->drawellipse(p2, UI.ASSGN_WDTH, UI.ASSGN_HI, "END");
	pOut->Drawconnector(p3, p4, true);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.8- Draw String TEST
	//Drawing a String in a specific location
	pOut->PrintMessage("Drawing A String, Click to continue");
	
	//Note: the function of this drawing is already implemented in Output class , you only need to call it
	

	////////////
	//TODO: Add code to: 
	// 1- Get a String from the user --> using the already-implemented Input::GetString(...) fn
	// 2- Draw that string in location (400, 200) --> using the already-implemented Output::DrawString(...) fn
	////////////
	string Str=pIn->GetString(pOut);
	pOut->DrawString(400,200,Str);//draws the string that its gets from the input of the user.


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings and a value from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings, values, variables and operators");

	pOut->PrintMessage("TEST0: Testing the input functions");
	double value = pIn->GetValue(pOut);
	pOut->PrintMessage("The value " + to_string(value));
	pIn->GetPointClicked(P);

	pOut->PrintMessage("TEST1: Testing the input functions");
	string variable = pIn->GetVariable(pOut);
	pOut->PrintMessage("The variable " + variable);
	pIn->GetPointClicked(P);

	pOut->PrintMessage("TEST2: Testing the input functions");
	string arthOperator = pIn->GetArithOperator(pOut);
	pOut->PrintMessage("The arthimaticOperator " + arthOperator);
	pIn->GetPointClicked(P);

	pOut->PrintMessage("TEST3: Testing the input functions");
	string compOperator = pIn->GetCompOperator(pOut);
	pOut->PrintMessage("The compOperator " + compOperator);
	pIn->GetPointClicked(P);

	////////////
	//TODO: Add code here to 
	// 1- Read a (double value) from the user and print it
	// 2- Read a (variable name) from the user and print it
	// 3- Read an (arithmatic operator) from the user and print it
	// 4- Read a (comparison operator) from the user and print it
	////////////

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	////////////
	//TODO:  You must add a case for EACH action in the following (switch case)
	////////////
	////COMPLETE THE SWITCH CASE WITH ALL THE ACTIONS

	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_START:
			pOut->PrintMessage("Action: add start statement , Click anywhere");
			break;
		case ADD_END:
			pOut->PrintMessage("Action: add end statement , Click anywhere");
			break;

			case ADD_VALUE_ASSIGN:
				pOut->PrintMessage("Action: add value assignment statement , Click anywhere");
				break;

			case ADD_VAR_ASSIGN:
				pOut->PrintMessage("Action: add variable assignment statement , Click anywhere");
				break;

			case ADD_OPER_ASSIGN:
				pOut->PrintMessage("Action: add operator assignment statement , Click anywhere");
				break;

			case ADD_READ:
				pOut->PrintMessage("Action: add read statement , Click anywhere");
				break;

			case ADD_WRITE:
				pOut->PrintMessage("Action: add write statement , Click anywhere");
				break;

			case ADD_CONDITION:
				pOut->PrintMessage("Action: add conditional statement , Click anywhere");
				break;

			case ADD_CONNECTOR:
				pOut->PrintMessage("Action: add a connector , Click anywhere");
				break;

			case DEL:
				pOut->PrintMessage("Action: delete a figure , Click anywhere");
				break;

			case COPY:
				pOut->PrintMessage("Action: copy a figure , Click anywhere");
				break;

			case CUT:
				pOut->PrintMessage("Action: cut a figure , Click anywhere");
				break;

			case PASTE:
				pOut->PrintMessage("Action: paste a figure , Click anywhere");
				break;

			case EDIT_STAT:
				pOut->PrintMessage("Action: edit a statement, Click anywhere");
				break;

			case SELECT:
				pOut->PrintMessage("Action: select action, Click anywhere");
				break;

			
			case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
 
			case DSN_TOOL:
				pOut->PrintMessage("Action: a click on the Design Tool Bar, Click anywhere");
				break;

			case SWITCH_SIM_MODE:
				pOut->PrintMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
				pOut->CreateSimulationToolBar(); // THIS TESTS Output::CreateSimulationToolBar() function //////
				break;

			case SWITCH_DSN_MODE:
				pOut->PrintMessage("Action: Switch to Design Mode, creating Design tool bar");
				pOut->CreateDesignToolBar();
				break;


			case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(P);


	delete pIn;
	delete pOut;	
	return 0;
}


