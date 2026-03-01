#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int numcases = 10;


void generateItem(int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << rand() % 10 << " ";
    }
    cout << endl;
}
void generateCase()
{
    int num = 2 + (rand() % 10);
    generateItem(num);
}
int main()
{
    srand(time(0));
    for (int i = 0; i < numcases; i++)
        generateCase();
}