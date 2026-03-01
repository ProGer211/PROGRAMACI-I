// reserveowddwords.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string.h>


using namespace std;

void girarparaules(int i)
{   
    string s;
    if (not(cin >> s)) return;  
    girarparaules(i + 1);
    if (i % 2  == 1 )
    {
        cout << s << endl;
    }
    
    
    
}

int main()
{
    int i = 1;
    
    girarparaules(i);
    
}

