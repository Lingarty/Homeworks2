/* Разделить список на 2: в одном цифры, в другом буквы */
#include <iostream>
#include "list_char.h"

using namespace std;

bool is_letter(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

bool is_numeral(char c)
{
	return (c >= '0' && c <= '9');
}

void Divide(Linked_list *list, Linked_list *letters, Linked_list *numerals)
{
	Node *current = new Node;
	current = list->head;

	while (current != NULL)
	{
		if (is_letter(current->value))
		{
			Add(letters, current->value);
		}
		else if (is_numeral(current->value))
		{
			Add(numerals, current->value);
		}
		current = current->next;
	}
}

int main()
{	
	Linked_list *list = new Linked_list;
	Linked_list *numerals = new Linked_list;
	Linked_list *letters = new Linked_list;
	Create_list(list);
	Create_list(numerals);
	Create_list(letters);

	cout << "Введите данные (в конце ввода поставьте *): " << endl;
	Read(list);

	Divide(list, letters, numerals);

	cout << "Буквы: " << endl;
	Show(letters);
	cout << endl;
	cout << "Цифры: " << endl;
	Show(numerals);
	cout << endl;
		
	return 0;
}
