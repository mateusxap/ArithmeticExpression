#pragma once
#include "Stack.h"
//int const sizeOfOp = 6;




class ArithmeticExpression
{
	std::string infix;
	std::string postfix;
	bool Check();
public:
	void Input();
	void ConvToPostfix();
	double Calculation();
	void ShowPostfix();
};

