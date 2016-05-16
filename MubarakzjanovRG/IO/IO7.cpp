/*
	IO7. Перевернуть текст
*/
#include <iostream>
#include <fstream>

using namespace std;

void print(char *text, int i)
{
	if (i == 0)
	{
		cout << "Файл пуст";
	}
	else
	{
		for (int j = i - 2 /* не печатаем endl */; j >= 0; j--)
		{
			cout << text[j];
		}
		cout << endl;
	}
}

void reflection(char *text)
{
	ifstream file;
	file.open("IO7-input.txt");
	char c;
	int i = 0;
	if (file)
	{
		while (!file.eof())
		{
			c = file.get();
			text[i] = c;
			i++;
		}
		print(text, i);
		file.close();
	}
	else
	{
		cout << "Файл не найден" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char text[10000];
	reflection(text);

	return 0;
}
