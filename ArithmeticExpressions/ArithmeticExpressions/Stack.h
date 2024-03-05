#pragma once
#include <iostream>
#include <cstdlib>
#include <map>
const int MAX = 100;

class Stack
{
	int top;
	double *pMem;
	int size;
public:
	Stack(int _size = MAX);
	~Stack();
	bool IsEmpty() const;
	bool IsFull() const	;
	void Push(double val);
	double Pop();
	double Last();
};

