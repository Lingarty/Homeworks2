/* 
	List1. Найти длину l самого длинного слова в тексте t и само это слово v. 
	Текст и слова заданы списком символов.
*/

#include <stdio.h>
#include <iostream>
#include "linked_list.h"


int isSeporator(char c) // check the symbol, is it separator between words?
{
	return !(c>='a' && c<='z' || c>='A' && c<='Z');
}

int The_longest_word(Linked_list *t, Linked_list *&v) // returns the longest word in the text and the length of this word
{
	int length = 0;
	int max_length = 0;

	Node *current = t->head;
	Node *max = current;
	Node *temp = t->head;

	while (temp != NULL)
	{
		if (!isSeporator(temp->value))
		{
			length++;
		}
		else 
		{
			if (length > max_length)
			{
				max_length = length;
				max = current;
			}
			length = 0;
			current = temp->next;
		}
		temp = temp->next;
	}

	if (length > max_length)
	{
		max_length = length;
		max = current;
	}

	v->head = max;
	temp = max;
	while (temp->next && !isSeporator(temp->next->value))
	{
		temp = temp->next;
	}
	temp->next = NULL;

	return max_length;
}


int main()
{
	Linked_list *t = new Linked_list;
	Linked_list *v = new Linked_list;
	Create_list(t);
	Create_list(v);

	Read(t);
	int l = The_longest_word(t, v);

	printf("Самое длинное слово в тексте: ");
	Print(v);
	printf("\nЕго длина: %d\n", l);

	return 0;
}
