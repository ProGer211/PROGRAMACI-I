
#include <iostream>
#include <string>

using namespace std;

// Adapt the header of the function to your case
int maximumDigit(int x)
{
    if (x > 0)
    {
        int b  = maximumDigit(x / 10);
        int c = x % 10;
        if (b > c)
        {
            return b;
        }
        return c;
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
        cout << maximumDigit(n) << endl;
}

