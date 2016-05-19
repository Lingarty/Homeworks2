/* Найти длину самого длинного слова в тексте. 
   Слово и текст заданы списком символов. */

#include <iostream>
#include "list_char.h"

using namespace std;

bool is_letter(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

int longest_word(Linked_list *text)
{
	int length = 0;
	int max_length = 0;

	Node *current = new Node;
	current = text->head;

	while(current != NULL)
	{
		if (is_letter(current->value))
			length++;
		else if (length > max_length)
		{
			max_length = length;
			length = 0;
		}
		current = current->next; 
	}
	if (length > max_length)
		max_length = length;

	return max_length;
}

int main()
{
	Linked_list *text = new Linked_list;
	Create_list(text);

	cout << "Введите текст (в конце ввода поставьте *): " << endl;
	Read(text);
	cout << "Длина самого длинного слова: " << longest_word(text) << endl;

	return 0;
}
