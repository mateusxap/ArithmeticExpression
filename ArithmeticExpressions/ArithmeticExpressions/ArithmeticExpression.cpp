#include "ArithmeticExpression.h"


std::map<double, int> operations = { {'(', 0}, {')', 1}, {'*', 3}, {'/', 3}, {'+', 2}, {'-', 2} };

bool ArithmeticExpression::Check()
{
	bool res = 1;
	size_t lBr = 0, rBr = 0;
	std::cout << "Левые скобки        Правые скобки\n";
	int errCount = 0;
	int brCount = 0;
	Stack stack(infix.size());
	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] == '(') {
			stack.Push(++brCount);
		}
		else if (infix[i] == ')') {
			brCount++;
			if (!stack.IsEmpty()) {
				std::cout << stack.Pop() << "                  " << brCount << std::endl;
			}
			else {
				errCount++;
				std::cout << 0 << "                  " << brCount << std::endl;
			}
			if (infix[i + 1] == '(')
			{
				std::cout << "Ошибка! Нет операций между скобками\n"; errCount++;
			}
		}
	}
	while (!stack.IsEmpty()) {
		errCount++;
		std::cout << stack.Pop() << "                  " << 0 << std::endl;
	}
	std::cout << "Кол-во ошибок: " << errCount << std::endl << std::endl;
	if (errCount > 0) {
		res = 0;
	}
	return res;
}


void ArithmeticExpression::Input()
{
	std::cout << "Введите арифметическое выражение:\n";
	std::cin >> infix;
	postfix.clear();
}
void ArithmeticExpression::ConvToPostfix()
{
	int errCount = 0;
	if (Check())
	{
		int size = infix.size();
		Stack stack(size);
		for (int i = 0; i < size; i++)
		{
			/*if (infix[i] == ' ') continue;
			else */
			if (operations.count((double)infix[i]) == 0) //если число
			{
				postfix += infix[i];
				int countOfDot = 0;
				while (!(operations.count((double)infix[i + 1]) > 0) && infix[i + 1] != '\0')
				{
					i++;
					if (infix[i] == '.')
						countOfDot++;
					postfix += infix[i];
				}
				if (countOfDot > 1)
				{
					std::cout << "Ошибка! Число введено некорректно\n";
					exit(0);
				}
					
				postfix += " ";
			}
			else if (infix[i] == '(')
			{
				stack.Push((double)'(');
				if (infix[i + 1] == '-')
				{
					postfix += "0 ";
				}
			}
			else if (infix[i] == ')')
			{
				while (stack.Last() != (double)'(')
				{
					if (!stack.IsEmpty())
					{
						postfix += (char)stack.Pop();
						postfix += " ";
					}
					else std::cout << "Ошибка! Выражение некорректно\n";
				}
				stack.Pop(); //убираем (
			}
			else if (operations.count((double)infix[i]) > 0)
			{
				while (!stack.IsEmpty() && operations[(double)infix[i]] <= operations[(double)stack.Last()]) //<><><><><><><
				{
					postfix += (char)stack.Pop();
					postfix += " ";

				}

				stack.Push(infix[i]);
				/*else
				{
					stack.Push(infix[i]);
				}*/
				//stack.Push(infix[i]);
			}
		}
		double sym;
		while (!stack.IsEmpty())
		{
			sym = stack.Pop();
			if (operations.count(sym) == 0) std::cout << "Ошибка! Выражение некорректно\n";
			postfix += (char)sym;
			postfix += " ";
		}
	}
	else
	{
		std::cout << "Ошибка!";
	}
	
}


double ArithmeticExpression::Calculation()
{
	std::setlocale(LC_NUMERIC, "C"); // чтобы правильно воспринимал . в вещественных числах
	int size = postfix.size() + 1;
	std::string number;
	double op1, op2, res;
	Stack stack(size);
	for (int i = 0; i < size; i++)
	{
		if (postfix[i] == '\0')
		{
			if (!stack.IsEmpty())
			{
				return(stack.Pop());
			}
			else
				return 0;
		}
		else if (postfix[i] == ' ') continue;
		else if (operations.count((double)postfix[i]) == 0) // если не оперетар
		{
			std::string number;
			char symbol = postfix[i];
			number += symbol;
			while (postfix[i + 1] != '\0' && postfix[i + 1] != ' ')
			{
				i++;
				char symbol = postfix[i];
				number += symbol;
			}
			for (int i = 0; i < number.size(); i++)
			{
				if (number[i] == '0' || number[i] == '1' || number[i] == '2' || number[i] == '3' || number[i] == '4' || number[i] == '5' || number[i] == '6' || number[i] == '7' || number[i] == '8' || number[i] == '9' || number[i] == '.')
				{
					continue;
				}
				else
				{
					std::cout << "Перед нами буква, нельзя посчитать";
					exit(0);
				}
			}
			const char* cStr = number.c_str();
			double num = std::strtod(cStr, nullptr); 
			stack.Push(num);
		}
		else // если оперетар
		{
			if (!stack.IsEmpty())
			{
				op2 = stack.Pop();
			}
			else
			{
				std::cout << "Ошибка! Не хватает операндов\n";
				break;
			}
			if (!stack.IsEmpty())
			{
				op1 = stack.Pop();
			}
			else
			{
				std::cout << "Ошибка! Не хватает операндов\n";
				break;
			}
			/// <summary>
			/// 
			/// </summary>
			/// <returns></returns>
			if (postfix[i] == '+')
				stack.Push(op1 + op2);
			else if (postfix[i] == '-')
				stack.Push(op1 - op2);
			else if (postfix[i] == '*')
				stack.Push(op1 * op2);
			else if (postfix[i] == '/')
			{
				if (op2 == 0)
				{
					std::cout << "Ошибка! Деление на 0\n";
					exit(0);
				}
				else stack.Push(op1 / op2);
			}
				
		}
	}
	
	
	
}

void ArithmeticExpression::ShowPostfix()
{
	std::cout << postfix;
}
