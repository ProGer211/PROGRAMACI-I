
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

// Addapt the header of the function to your case
using namespace std;

void remove01Rec(queue<int>& q, queue<int> f)
{
    int i = 0;
    while (not(q.empty()))
    {
        int a = q.front();
        q.pop();
        if (a == 0)
        {
            if (i % 2 != 0) f.push(a);
        }
        else if (a == 1)
        {
            if (i % 2 == 0) f.push(a);
        }
        else f.push(a);

        i++;
    }
}

queue<int> remove01(queue<int> q)
{
    queue<int> f;
    remove01Rec(q, f);
    return f;
}

queue<int> readQueue(string s)
{
    istringstream mycin(s);
    queue<int> q;
    int x;
    while (mycin >> x)
        q.push(x);
    return q;
}

void writeQueue(queue<int> q)
{
    bool writespace = false;
    while (not q.empty()) {
        if (writespace) cout << " ";
        cout << q.front();
        q.pop();
        writespace = true;
    }
    cout << endl;
}

// Addapt the call to 'function_name' and the way it is called to your case.
int main() {
    vector<queue<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readQueue(s));
    for (int i = 0; i < int(v.size()); ++i)
        writeQueue(remove01(v[i]));
}
