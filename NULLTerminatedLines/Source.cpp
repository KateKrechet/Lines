#include<iostream>
#include<windows.h>
#include<string.h>
#include<cmath>

using namespace std;
int StringLength(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
void remove_symbol(char str[], const char symbol);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
int to_int_number(char str[]);
bool is_bin_number(char str[]);
int bin_to_dec(char str[]);
bool is_hex_number(char str[]);
int hex_to_dec(char str[]);

void main()
{
	//for (int i = 0; i < 256; i++) cout << i << "\t" << char(i) << endl;
	setlocale(LC_ALL, "");
	//char str[] = { 'H','e','l','l','o','\0' };
	//char str[] = "Hello";
	const int n = 256;
	//char str[n]="Хорошо  живет  на     свете Винни-Пух";
	char str[n] = "Аргентина манит     негра";
	//cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//cin.getline(str, n);
	cout << str << endl;
	cout << "Количество элементов строки: " << StringLength(str) << endl;
	to_upper(str);
	cout << "Заглавными буквами: " << str << endl;
	to_lower(str);
	cout << "Заглавными буквами: " << str << endl;
	shrink(str);
	cout << "Убираем лишние пробелы: " << str << endl;
	cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	cout << "Введите строку: ";
	cin >> str;
	cout << "Строка " << (is_int_number(str) ? "" : "НЕ ") << "является целым десятичным числом" << endl;
	//cout << "Количество элементов строки: " << StringLength(str) << endl;
	cout << "Десятичное число: "<<to_int_number(str)<<endl;
	cout << "Введите строку: ";
	cin >> str;
	cout << "Строка " << (is_bin_number(str) ? "" : "НЕ ") << "является целым двоичным числом" << endl;
	cout << "Двоичное число в десятичном формате: " << bin_to_dec(str) << endl;
	cout << "Введите строку: ";
	cin >> str;
	cout << "Строка " << (is_hex_number(str) ? "" : "НЕ ") << "является целым шестнадцатиричным числом" << endl;
	cout << "Шестнадцатиричное число в десятичном формате: " << hex_to_dec(str) << endl;
}

int StringLength(char str[])

{
	int i = 0;
	for (; str[i]; i++);
	//while (str[i] != '\0') i++;
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= 'а' && str[i] <= 'я'
			)
			str[i] -= 32;
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'А' && str[i] <= 'Я'
			)
			str[i] += 32;
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == 0))
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}

}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1]{};
	for (int i = 0; str[i]; i++) buffer[i] = str[i];
	to_upper(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i]) return false;
	}
	return true;
}
bool is_int_number(char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}

int to_int_number(char str[])
{
	int sum = 0;
	int n = strlen(str);
	if (is_int_number(str))
	{
		for (int i = 0; i < n; i++)
		{
			sum = sum + ((str[i] - 48) * pow(10, n - 1 - i));
		}
		return sum;
	}
	else return 0;
}
bool is_bin_number(char str[])
{
	int n = strlen(str);
	if (str[n - 1] != 'b') return false;
	for (int i = 0; i < n-1; i++)
	{
		if (str[i] < '0' || str[i] > '1') return false;
	}
	return true;
}
int bin_to_dec(char str[])
{
	int sum = 0;
	int n = strlen(str);
	if (is_bin_number(str))
	{
		for (int i = 0; i < n - 1; i++)
		{
			sum = sum + ((str[i] - 48) * pow(2, n - 2 - i));
		}
		return sum;
	}
	else return 0;
}
bool is_hex_number(char str[])
{
	int n = strlen(str);
	if (str[n - 1] != 'h') return false;
	for (int i = 0; i < n-1; i++)
	{
		if (str[i] < '0' || (str[i] > '9'&&str[i] < 'A') || str[i] > 'F'&& str[i] < 'a' || str[i] > 'f') return false;
	}
	return true;

}
int hex_to_dec(char str[])
{
	int sum = 0;
	int n = strlen(str);
	if (is_hex_number(str))
	{
		for (int i = 0; i < n - 1; i++)
		{
			sum = sum + (str[i] - ((str[i] >= 'A' && str[i] <= 'F') ? 55 :(str[i] >= 'a' && str[i] <= 'f')?('a'-10): 48)) * pow(16, n - 2 - i);
		}
		return sum;
	}
	else return 0;

}


