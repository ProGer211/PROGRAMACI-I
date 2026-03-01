// Exam ej 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int maximumDigit(int);

int main()
{
	int x, digit, result;
	
	cout << "Ingrese un numero :";
	cin >> x;

	digit = maximumDigit(x);
	cout << digit;

}

int maximumDigit(int x)
{
	if (x > 0)
	{
		if (x % 10 > maximumDigit(x / 10))
		{
			return x % 10;
		}				
	}
	else
	{
		return 0;
	}
	
}