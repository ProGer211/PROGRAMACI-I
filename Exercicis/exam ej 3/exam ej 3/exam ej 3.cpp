// exam ej 3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;
void caract(int);

int main()
{
	int n;
	cout << "Ingrese un numero: ";
	cin >> n;
	caract(n);
   
}

void caract(int n)
{
	if (n == 0) return;
	caract(n - 1);
	cout << string(n, '*') << endl;
	caract(n - 1);

}
