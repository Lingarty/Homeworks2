/*
	IO1. Найти самое длинное слово в тексте за один проход
*/
	
#include <iostream>
#include <fstream>

using namespace std;

int is_letter(char c)
{
	return (c >= 'a') && (c <= 'z') || (c >= 'A') && (c <= 'Z');
}

void print(char *w, int l)
{
	int i = 0;
	while (i < l)
	{
		cout << *(w + i);
		i++;
	}
}

void Max(int &max_length, char *max_word)
{
	ifstream file;
	file.open("IO1-input.txt");
	char c;
	int i = 0; // index for current word
	int length = 0;
	char word[50];

	if (file)
	{
		while (!file.eof())
		{
			c = file.get();
			if (is_letter(c))
			{
				length++;
				word[i] = c;
				i++;
			}
			else if (length > max_length)
			{
				max_length = length;
				for (int j = 0; j <= i; j++)
				{
					max_word[j] = word[j];
				}
				i = 0;
				length = 0;
			}
			else
			{
				i = 0;
				length = 0;
			}
		}
		file.close();
	}
	else
	{
		cout << "Файл не найден" << endl;
	}
}

void print_result(int max_length, char *max_word)
{
	cout << "Самое длинное слово в тексте: ";
	print(max_word, max_length);
	cout << endl;
	cout << "Его длина " << max_length << " символов" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int max_length = 0;
	char max_word[50];

	Max(max_length, max_word);
	print_result(max_length, max_word);

	return 0;
}
