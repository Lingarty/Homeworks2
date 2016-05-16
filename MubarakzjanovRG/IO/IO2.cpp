/*
	IO2. В файле заменить заданное слово другим заданным
	Входной файл обрабатывается сразу
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int isSeporator(char c)
{
	return !(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

void read(char *w)
{
	cin >> w;
}

void reading_data(char *w1, char *w2)
{
	cout << "Введите слово, которое будем заменять: ";
	read(w1);
	cout << endl << "Введите слово, на которое будем заменять: ";
	read(w2);
	cout << endl;
}

void replacement(char *w1, char *w2)
{
	ifstream file;
	file.open("IO2-input.txt");

	if (file)
	{	
		char c;
		int i = 0;
		while (!file.eof())
		{
			c = file.get();
			if(isSeporator(c))
			{
				if(strlen(w1) == i)
					cout << w2;
				else
					for(int j = 0; j < i; j++)
						cout << w1[j];
				i = 0;
				if(c != EOF)
					cout << c;
			}
			else if (c == w1[i])
			{
				i++;
			}
			else
			{
				for(int j = 0; j < i; j++)
					cout << w1[j];
				i = 0;
				cout << c;
			}
		}
		cout << endl;
		file.close();
	}
	else
	{
		cout << "Файл не найден";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");	

	char w1[50], w2[50];
	reading_data(w1, w2);
	replacement(w1, w2);

	return 0;
}
