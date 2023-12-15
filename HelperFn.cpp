#include "HelperFn.h"


//tesst
bool IsValue(string input)
{
	int size = input.length();
	for (int i = 0; i < size; i++) {
		int ch = input[i];
		if (!((ch >= 48 && ch <= 59) || ch == 45 || ch == 46)) {
			return false;
		}
	}
	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//TODO: complete this function

	return true;
}

bool IsVariable(string input)
{
	int firstch = input[0];
	if ((firstch >= 97 && firstch <= 122) || (firstch >= 65 && firstch <= 90) || firstch == 95) {
		return true;
	}
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.

	//TODO: complete this function

	return false;
}

OpType ValueOrVariable(string input)
{
	if (IsValue(input) == true) {
		return VALUE_OP;
	}
	else if (IsVariable(input) == true)
	{
		return VARIABLE_OP;
	}
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)

	//TODO: complete this function

	return INVALID_OP;
}
////test
//#include "HelperFn.h"
////DA TESTTTTTTTTTTTTTTT
///// <summary>
///// </summary>
///// <param name="input"></param>
///// <returns></returns>
//
//
//bool IsValue (string input)
//{
//	// checks if the input string is a double value
//	// return true if it's double value, false otherwise
//
//	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.
//
//	//TODO: complete this function
//
//	return false;
//}
//
//bool IsVariable(string input)
//{
//	// checks if the input string is a variable name
//	// return true if it can be a variable name, false otherwise
//
//	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
//	// After the first initial letter, variable names can contain letters, numbers and underscores.  
//	// No spaces or special characters, however, are allowed.
//
//	//TODO: complete this function
//
//	return false;
//}
//
//OpType ValueOrVariable (string input)
//{
//	// checks if the input string is a double value or a variable name
//	// chand returns enum "OpType" (the enum is declared in the .h)
//
//	//TODO: complete this function
//
//	return INVALID_OP;
//}
