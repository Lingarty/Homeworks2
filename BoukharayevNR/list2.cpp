/* 
	List2: Удалить из текста t все вхождения заданного слово w. 
	Текст и слова заданы списком символов.
*/

#include <stdio.h>
#include <iostream>
#include "linked_list.h"


int is_letter(char c) // check the symbol, is it separator between words?
{
	return (c>='a' && c<='z' || c>='A' && c<='Z');
}

bool is_equal(Node *current, Node *current_w) // определяет равенство слов
{
	if (current_w != NULL && current->value == current_w->value && is_letter(current->value))
	{
		is_equal(current->next, current_w->next);
		Delete(current); 
	}
	else if (current_w == NULL && !is_letter(current->value))
		return true;
	else 
		return false;
}

int deletion(Linked_list *t, Linked_list *w)
{
	int num = 0; // количество вхождений заданного слова
	Node *current = t->head; // текущий узел в тексте
	Node *current_w = w->head; // текущий узел в слове на удаление
	Node *temp; // хранит узел, с которого возможно начнётся слово на удаление

	while (current != NULL)
	{
		if (is_letter(current->value))
		{
			if (is_equal(current, current_w))
			{
				num++;
				if (temp != NULL) // если удалили слово не в начале текста
					temp->next = current_w->next;
			}
		}
		else
		{
			temp = current;
		}
		current = current->next;
	}

	return num;
}

int main()
{
	Linked_list *t = new Linked_list;
	Linked_list *w = new Linked_list;
	Create_list(t);
	Create_list(w);

	cout << "Введите текст:" << endl;
	Read(t);
	cout << "Введите слово на удаление:" << endl;
	Read(w);
	
	if (deletion(t, w) > 0)
	{
		cout << "Вот, что получилось: " << endl;
		Print(t);
	}
	else
		cout << "Заданное слово не встречается в тексте" << endl;

	return 0;
}
