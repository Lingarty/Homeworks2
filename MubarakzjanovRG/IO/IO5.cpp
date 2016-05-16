/*
	IO5. В вводимом тексте подсчитать количество самых коротких слов
*/
#include <iostream>
#include <fstream>

using namespace std;

int is_letter(char c)
{
	return (c >= 'a') && (c <= 'z') || (c >= 'A') && (c <= 'Z');
}

void Min(int &min_length, int &count)
{
	ifstream file;
	file.open("IO5-input.txt");
	char c;
	int i = 0; // index for current word
	int length = 0;

	if (file)
	{
		while (!file.eof())
		{
			c = file.get();
			if (is_letter(c))
			{
				length++;
				i++;
			}
			else if (length < min_length && length != 0)
			{
				min_length = length;
				i = 0;
				length = 0;
				count = 1;
			}
			else if (min_length != 1000 && min_length == length)
			{
				count++;
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

void print_result(int min_length, int count)
{
	cout << "Минимальная длина слова, которую удалось найти: " << min_length << endl;
	cout << "Таких слов нашлось:  " << count << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int min_length = 1000;
	int count = 0;
	
	Min(min_length, count);
	print_result(min_length, count);

	return 0;
}
