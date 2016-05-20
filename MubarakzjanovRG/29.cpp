/* 29. Проверить правильность расстановки скобок в выражении */

#include <iostream>
#include "stack.h"

using namespace std;

bool is_right(Stack *stack)
{
	char c;
	char last_saved;
	int ended = 0;
	while (!ended)
	{
		c = (char)cin.get();
		ended = c == '\n';

		if (c == '(')
			Push(stack, c);
		else if (c == '{')
			Push(stack, c);
		else if (c == ')')
		{
			if (stack->head == NULL)
				return 0;
			else
			{
				last_saved = Pop(stack);
				if (last_saved != '(')
					return 0;
			} 
		}
		else if (c == '}')
		{
			if (stack->head == NULL)
				return 0;
			else
			{
				last_saved = Pop(stack);
				if (last_saved != '{')
					return 0;
			} 
		}
	}
}

int main()
{
	Stack *stack = new Stack;
	Create_stack(stack);

	cout << "Введите данные: " << endl;
	if(is_right(stack))
		cout << "Всё верно." << endl;
	else
		cout << "Скобки расставлены неверно." << endl;

	return 0;
}
