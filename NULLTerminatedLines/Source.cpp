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
	//char str[n]="������  �����  ��     ����� �����-���";
	char str[n] = "��������� �����     �����";
	//cout << "������� ������: ";
	//cin >> str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//cin.getline(str, n);
	cout << str << endl;
	cout << "���������� ��������� ������: " << StringLength(str) << endl;
	to_upper(str);
	cout << "���������� �������: " << str << endl;
	to_lower(str);
	cout << "���������� �������: " << str << endl;
	shrink(str);
	cout << "������� ������ �������: " << str << endl;
	cout << "������ " << (is_palindrome(str) ? "" : "�� ") << "�������� �����������" << endl;
	cout << "������� ������: ";
	cin >> str;
	cout << "������ " << (is_int_number(str) ? "" : "�� ") << "�������� ����� ���������� ������" << endl;
	//cout << "���������� ��������� ������: " << StringLength(str) << endl;
	cout << "���������� �����: "<<to_int_number(str)<<endl;
	cout << "������� ������: ";
	cin >> str;
	cout << "������ " << (is_bin_number(str) ? "" : "�� ") << "�������� ����� �������� ������" << endl;
	cout << "�������� ����� � ���������� �������: " << bin_to_dec(str) << endl;
	cout << "������� ������: ";
	cin >> str;
	cout << "������ " << (is_hex_number(str) ? "" : "�� ") << "�������� ����� ����������������� ������" << endl;
	cout << "����������������� ����� � ���������� �������: " << hex_to_dec(str) << endl;
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
			str[i] >= '�' && str[i] <= '�'
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
			str[i] >= '�' && str[i] <= '�'
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
	for (int i = 0; i < n; i++)
	{
		if ((str[i] < '0' || str[i] > '1')&&str[n-1] != 'b') return false;
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
	for (int i = 0; i < n; i++)
	{
		if ((str[i] < '0' || (str[i] > '9'&&str[i] < 'A') || str[i] > 'F')&&str[n-1] != 'h') return false;
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
			sum = sum + (str[i]-((str[i] > 'A'||str[i] < 'F') ? 55 : 48))* pow(16, n - 2 - i);
		}
		return sum;
	}
	else return 0;

}


