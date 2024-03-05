#include "Stack.h"
#include "ArithmeticExpression.h"
int main()
{
    setlocale(0, "");       

    ArithmeticExpression a;
    
    a.Input();
    a.ConvToPostfix();
    a.ShowPostfix();
    std::cout << "\n";
    std::cout << a.Calculation() << "\n";
 
    
	return 0;
}
//((2+3)/(9-4)+7)*(5-4)+4
//2+3*3
//(((1+2)))*3+5
// (2+1)(3+5)
//(((
//((()))

//)()(
//-(2+1)*52+(-6)
//(a+b)*c