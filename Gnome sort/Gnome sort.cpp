// Gnome sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const int lol = 10; // размер массива

class Fraction
{
private:
	int numerator, intPart;
	int denominator;

public:
	Fraction()
	{
		numerator = 0;
		denominator = 1;
		intPart = 0;
	}

	Fraction(int num, int denom, int intPrt = 0)
	{
		numerator = num;
		denominator = denom;
		intPart = intPrt;
	}

	bool operator > (Fraction a)
	{
		if (this->denominator == a.denominator)
		{
			return (this->numerator > a.numerator);
		}
		else
		{
			return((this->numerator * a.denominator) > (a.numerator * this->denominator));
		}
	}

	bool operator < (Fraction a)
	{
		if (this->denominator == a.denominator)
		{
			return (this->numerator < a.numerator);
		}
		else
		{
			return((this->numerator * a.denominator) < (a.numerator * this->denominator));
		}
	}

	bool operator >= (Fraction a)
	{
		if (this->denominator == a.denominator)
		{
			return (this->numerator >= a.numerator);
		}
		else
		{
			return((this->numerator * a.denominator) >= (a.numerator * this->denominator));
		}
	}

	bool operator <= (Fraction a)
	{
		if (this->denominator == a.denominator)
		{
			return (this->numerator <= a.numerator);
		}
		else
		{
			return((this->numerator * a.denominator) <= (a.numerator * this->denominator));
		}
	}

	friend ostream& operator << (ostream&, Fraction&);

	friend void proper_function(Fraction *a);
};

void Gnome_sort(Fraction *numerator)
{
	int m = 1, k = 2;

	while (m < lol)
	{
		if (numerator[m - 1] <= numerator[m])
		{
			m = k;
			k++;
		}
		else
		{
			Fraction tmp = numerator[m];
			numerator[m] = numerator[m - 1];
			numerator[m - 1] = tmp;

			m--;

			if (m == 0)
			{
				m = k;
				k++;
			}
		}
	}
}

ostream& operator << (ostream& out, Fraction& a)
{
	if (a.numerator < 0 && a.denominator < 0)
	{
		a.numerator *= -1;
		a.denominator *= -1;
	}
	else if (a.denominator < 0)
	{
		a.numerator *= -1;
		a.denominator *= -1;
	}

	if (a.numerator != 0) // если числитель не 0, вывод дроби
	{
		out << a.numerator << "/" << a.denominator << "\t";
	}

	if (a.intPart == 0 && a.numerator == 0) // если целая часть и числитель 0, вывод 0
	{
		out << 0 << "\t";
	}
	else if (a.numerator == 0)
	{
		out << 0 << "\t";
	}

	return out;
}

void proper_function(Fraction *a)
{
	for (int i = 0; i < lol; i++)
	{
		if (a[i].numerator == a[i].denominator)
		{
			a[i].intPart = 1;
			cout << a[i].intPart << "\t";
		}
		else if (a[i].denominator == 1)
		{
			cout << a[i].numerator << "\t";
		}
		else if (abs(a[i].numerator) > a[i].denominator)
		{
			if (a[i].numerator < 0)
			{
				a[i].intPart = a[i].numerator / a[i].denominator;
				a[i].numerator *= -1;
				a[i].numerator += a[i].denominator * a[i].intPart;
			}
			else if (a[i].denominator < 0)
			{
				a[i].intPart = a[i].numerator / a[i].denominator;
				a[i].denominator *= -1;
				a[i].numerator -= a[i].denominator * a[i].intPart;
			}
			else
			{
				a[i].intPart = a[i].numerator / a[i].denominator;
				a[i].numerator -= a[i].denominator * a[i].intPart;
			}

			if (a[i].numerator == 0)
			{
				cout << a[i].intPart << "\t";
			}
			else
			{
				cout << a[i].intPart << "->" << a[i].numerator << "/" << a[i].denominator << "\t\t";
			}
		}
		else
		{
			//cout << a[i].numerator << "/" << a[i].denominator << "\t";
			cout << a[i] << "\t";
		}
	}
}

int main()
{
	srand(time(NULL));

	Fraction r1[lol];
	int arr_num[lol], arr_denom[lol];

	for (int i = 0; i < lol; i++)
	{
		arr_num[i] = rand() % (lol*2 + 1) - lol;
		arr_denom[i] = rand() % (lol * 2 + 1) - (lol + 1);
	}

	for (int i = 0; i < lol; i++)
	{
		r1[i] = Fraction(arr_num[i], arr_denom[i], 0);
	}

	cout << "Unsorted array of fractions: " << endl;
	for (int i = 0; i < lol; i++)
	{
		cout << r1[i] << ends;
	}
	cout << endl << endl;

	Gnome_sort(r1);

	cout << "Sorted array of fractions: " << endl;
	for (int i = 0; i < lol; i++)
	{
		cout << r1[i] << ends;
	}
	cout << endl << endl;

	cout << "Corrected array of fractions: " << endl;
	proper_function(r1);
	cout << endl;
}