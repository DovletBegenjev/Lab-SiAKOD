// Лаба 1 СиАКОД.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <list>
#include <iterator>
#include <conio.h>
using namespace std;

/*void BinOut(char buff_ptr)//, int* sizebuff)
{
	int n = buff_ptr, w;
	list<int> num;
	list<int> num2;

	if (buff_ptr < 0)
	{
		buff_ptr *= -1;

		while (buff_ptr != 0)
		{
			n = buff_ptr % 2;
			buff_ptr = buff_ptr / 2;
			num.push_front(n);
		}

		//copy(num.begin(), num.end(), ostream_iterator<int>(cout, ""));

		w = 32 - num.size();

		for (int i = 0; i < w; i++)
		{
			num.push_front(0);
		}

		for (int i : num)
		{
			if (i == 0)
			{
				i = 1;
			}
			else
			{
				i = 0;
			}

			num2.push_back(i);
		}

		if (num2.back() == 1)
		{
			for (auto i = num2.end(); i != num2.begin(); i--)
			{
				//cout << *i;
			}
		}

		cout << endl;
		copy(num2.begin(), num2.end(), ostream_iterator<int>(cout, ""));
		cout << endl;
	}
	else
	{
		while (buff_ptr != 0)
		{
			n = buff_ptr % 2;
			buff_ptr = buff_ptr / 2;
			num.push_front(n);
		}

		copy(num.begin(), num.end(), ostream_iterator<int>(cout, ""));

		w = 32 - num.size();

		for (int i = 0; i < w; i++)
		{
			num.push_front(0);
		}

		cout << endl;
		copy(num.begin(), num.end(), ostream_iterator<int>(cout, ""));
		cout << endl;
	}
}*/

char* BinOut(unsigned char *Buf, int len) 
{
	int i, j;
	char *arr = new char[32];
	unsigned char byte;
	for (i = len - 1; i >= 0; i--)
	{
		for (j = 1, byte = Buf[i]; j <= 8; byte <<= 1, j++)
		{
			arr[i] = _putch(byte & 0x80 ? '1' : '0');
		}
	}
	printf("\n");
	
	return arr;
}

void BinIn(unsigned char* Buf, int len)
{
	int i, j;
	char ch;
	for (i = len - 1; i >= 0; i--)
	{
		for (j = 1, Buf[i] = 0; j <= 8; Buf[i] = (Buf[i] << 1) + (ch - '0'), j++)
		{
			while ((ch = _getch()) != '0' && ch != '1');
			_putch(ch);
		}
	}
	printf("\n");
}

int main()
{
	long q;
	cout << "Enter number (long): ";
	cin >> q;
	char* arr = BinOut((unsigned char*)&q, sizeof(q));
	cout << arr << endl;
	for (int i = 0; i < 32; i++)
	{
		_putch(*arr);
	}

	delete[] arr;

	cout << "Enter binary number: " << endl;
	BinIn((unsigned char*)&q, sizeof(q));
	cout << q << endl;

	float w;
	cout << "Enter number (float): ";
	cin >> w;
	BinOut((unsigned char*)&w, sizeof(w));

	cout << "Enter binary number: " << endl;
	BinIn((unsigned char*)&w, sizeof(w));
	cout << w << endl;

	char r[3][3];
	cout << "Enter array of symbols (char): " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> r[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			BinOut((unsigned char*)&r[i][j], sizeof(r[i][j]));
		}
	}

	cout << "Enter array of binary numbers of symbols: " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			BinIn((unsigned char*)&r[i][j], sizeof(r[i][j]));
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << r[i][j] << ends;
		}
		cout << endl;
	}
}