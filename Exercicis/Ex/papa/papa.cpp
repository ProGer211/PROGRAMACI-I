// Add or remove includes
#include <iostream>
#include <string>
#include<stdio.h>
#include<math.h>

using namespace std;

// Adapt the header of the function to your case
int simpleAlternatedSum(int n)
{
    if (n >= 1)
    {
        return (pow(-1, n + 1) * n) + simpleAlternatedSum(n - 1);
    }
    else
    {
        return 0;
    }
}


// Adapt the call to 'function_name' and the way it is called to your case.
int main() {
    int n;
    while (cin >> n)
        cout << simpleAlternatedSum(n) << endl;
}

