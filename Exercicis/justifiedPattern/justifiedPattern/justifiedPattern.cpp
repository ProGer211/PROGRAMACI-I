

#include <iostream>
#include <string>

using namespace std;

void caract(int n, char c)
{
    if (n == 0) return;
        caract(n - 1, c);
        cout << string(n, c) << endl;
        caract(n - 1, c);   
}

int main()
{
    int n;
    cin >> n;
    char c;
    cin >> c;
    caract(n, c);
}

