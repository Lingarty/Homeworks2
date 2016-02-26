#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Node {
    char ch;
    Node* next;
};

struct Linked_list {

    Node* first;
    Node* last;

    Linked_list() {
        first = NULL;
        last = NULL;
    }
};

void Add(char c, Linked_list *list) {

    Node* node = new Node;

    (*node).ch= c;
    (*node).next = NULL;

    if ((*list).first == NULL)
    {
        (*list).first = node;
        (*list).last = node;
    }
    else
    {
        (*list).last->next = node;
        (*list).last = node;
    }
}


void Read(Linked_list *list) {

    char c;

    while (scanf("%c", &c) != '.') { //почему не прерывается ввод?

        Add(c, list);
    }
}

void Max(Linked_list *list) {
    int maxLength = 0;
    char maxword[30]="";
    int currLength = 0;
    char currWord[30] = "";
    Node *temp = (*list).first;
    while (temp!= NULL)
    {
        if (temp->ch != ' ' && temp->ch!= '.' && temp->ch != ',')
        {
            currWord[currLength] = temp->ch;
            currLength++;
        }
        else
        {
            if (currLength > maxLength)
            {
                maxLength = currLength;
                for (int i = 0; i < 30; i++)
                {
                    maxword[i] = currWord[i];
                }
            }
            for (int i = 0; i < 30; i++)
            {
                currWord[i] = 0;
            }
            currLength = 0;
        }
        temp = temp->next;
        if(temp==NULL)
        if (currLength > maxLength)
        {
            maxLength = currLength;
            for (int i = 0; i < 30; i++)
            {
                maxword[i] = currWord[i];
            }
        }
    }
    std::cout << maxword << ' ' << maxLength << std::endl;
}
int main() {

    Linked_list *list = new Linked_list;
    Read(list);
    Max(list);

    return 0;
}