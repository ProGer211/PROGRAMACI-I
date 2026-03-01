// Examen ej 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <math.h>

using namespace std;
int simpleAlternatedSum(int);

int main()
{
    int n, result;
    cout << "Ingrese un numero: ";
    cin >> n;

    result = simpleAlternatedSum(n);
    cout << result;

}

int simpleAlternatedSum(int n)
{
    if (n>=1)
    {
        return (pow(-1, n + 1) * n) + simpleAlternatedSum(n - 1);
    }
    else
    {
        return 0;
    }
}
