/*
	IO4. В вводимом тексте подсчитать количество самых длинных слов
*/
#include <iostream>
#include <fstream>

using namespace std;

int is_letter(char c)
{
	return (c >= 'a') && (c <= 'z') || (c >= 'A') && (c <= 'Z');
}

void Max(int &max_length, int &max_count)
{
	ifstream file;
	file.open("IO4-input.txt");
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
			else if (length > max_length)
			{
				max_length = length;
				i = 0;
				length = 0;
			}
			else if (max_length != 0 && max_length == length)
			{
				max_count++;
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

void print_result(int max_length, int max_count)
{
	cout << "Максимальная длина слова, которую удалось найти: " << max_length << endl;
	cout << "Таких слов нашлось:  " << max_count << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int max_length = 0;
	int max_count = 0;
	
	Max(max_length, max_count);
	print_result(max_length, max_count);

	return 0;
}
