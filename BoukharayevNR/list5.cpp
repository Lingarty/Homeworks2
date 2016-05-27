/*
	List 5. Проверить вхождение слова в текст (как сплошного фрагмента). 
	Текст и слова заданы списком символов.
*/

#include <stdio.h>
#include <iostream>
#include "linked_list.h"

bool found(Linked_list *t, Linked_list *w)
{
	Node *current_t = new Node;
	current_t = t->head;
	Node *current_w = new Node;
	current_w = w->head;
	
	while (current_t != NULL)
	{
		while (current_t->value == current_w->value && current_t->next != NULL && current_w->next != NULL) // пробегаем одинаковые символы
		{
			current_t = current_t->next;
			current_w = current_w->next;
		}

		if (current_w->next == NULL) //если сопал весь фрагмент
			return true;
		else // или его часть 
			current_w = w->head;

		if (current_t != NULL)
			current_t = current_t->next;
	}
	return false;
}

int main()
{
	Linked_list *t = new Linked_list;
	Linked_list *w = new Linked_list;
	Create_list(t);
	Create_list(w);

	cout << "Введите текст:" << endl;
	Read(t);
	cout << "Введите фрагмент для поиска:" << endl;
	Read(w);

	if (found(t, w))
		cout << "Заданная последовательность символов является фрагментом текста. " << endl;
	else
		cout << "Заданная последовательность символов не встречается в тексте." << endl;

	return 0;
}
