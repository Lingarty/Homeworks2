#include <iostream>

using namespace std;

int count = 0; // число элементов в списке

struct Node
{
	int value;
	Node *next;
};

struct Linked_list
{
	Node *head;
};

void Create_list(Linked_list *list)
{
	list->head = NULL;
}

void Add(Linked_list *list, int value)
{
	Node *node = new Node;
	node->value = value;
	node->next = list->head;
	list->head = node;
	count++;
}

void Delete(Linked_list *list) // удаление узла-головы
{
	Node *temp = new Node;
	temp = list->head;
	list->head = list->head->next;
	delete temp;
	count--;
}

void Read(Linked_list *list)
{
	int value;
	cin >> value;
	while (value != 0)
	{
		Add(list, value);
		cin >> value;
	}
}

void Show(Linked_list *list) // выводит "задом наперёд", первый добавленный элемент в конце
{
	Node *current = new Node;
	current = list->head;

	while (current->next != NULL)
	{
		cout << current->value << ' ';
		current = current->next;
	}
}

void Print(Node *node) // выводит в порядке добавлнения, первый добавленный элмент в первую очередь
{
	Node *temp = node;

	if (temp == NULL)
	{
		return;
	}
	else
	{
		Print(temp->next);
		cout << temp->value;
		cout << ' ';
	}
}

void Print (Linked_list *list) // оболочка одноимённой функции для удобства пользователя
{
	Print(list->head);
}

void Dispose(Linked_list *list) // delete list and release memory
{
	Node *temp = new Node;
	temp = list->head;

	while (temp != NULL) 
	{
		list->head = list->head->next;
		delete temp;
		count--;
		temp = list->head;
	}
}
