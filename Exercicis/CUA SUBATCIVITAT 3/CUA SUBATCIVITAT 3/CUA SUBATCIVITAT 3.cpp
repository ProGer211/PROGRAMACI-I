
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

queue<int> remove01(queue<int> q)
{
    int capacidad = q.size();
    queue<int> final;
    for (int i = 0; i < capacidad; i++)
    {
        int k = q.front();
        if (k == 0 && i % 2 == 0) 
        {
            q.pop();
        }
        else if ((k == 1) && (i % 2 != 0) && (i != 0))
        {
            q.pop();
        }
        else
        {
            q.pop();
            final.push(k);
        }

    }
    return final;
}



int main() 
{
    queue<int> q;
    int x;
    while (cin >> x)
    {
        q.push(x);
    }
    q = remove01(q);
    while (not(q.empty()))
    {
        int t = q.front();
        cout << t << " ";
        q.pop();
    }
}

