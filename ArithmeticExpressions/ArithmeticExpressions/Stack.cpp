#include "Stack.h"

Stack::Stack(int _size): size( _size)
{
	if (size <= 0) throw std::runtime_error("Ошибка, размер стэка должен быть больше 0");
	pMem = new double[size];
	top = -1;
}
Stack::~Stack()
{
	delete[]pMem;
}
bool Stack::IsEmpty() const 
{
	return (top == -1);
}
bool Stack::IsFull() const
{
	return (top == (size - 1));
}
void Stack::Push(double val) 
{
	pMem[++top] = val;
}
double Stack::Pop()
{
	return pMem[top--];
}
double Stack::Last()
{
	return pMem[top];
}