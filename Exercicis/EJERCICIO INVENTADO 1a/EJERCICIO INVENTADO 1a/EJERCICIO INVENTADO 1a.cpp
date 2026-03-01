#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

stack<int> reverse_aux(stack<int> s, int x1, int x2, stack<int> sub)
{
    if (not(s.empty()))
    {
        int k = s.top();
        s.pop();
        reverse_aux(s, x1, x2, sub);
        if (s.size() == x1)
        {
            sub.push(k);
            if ((s.size() + sub.size() - 1) == x2)
            {
                int c = sub.size();
                for (int i = 0; i < c; i++)
                {
                    int t = sub.top();
                    sub.pop();
                    s.push(t);
                }
            }
        }
        else
        {
            s.push(k);
        }
    }
    return s;

}
stack<int> reverse(stack<int> s, int x1, int x2)
{
    stack<int> sub;
    reverse_aux(s, x1, x2, sub);
    return s;
}
#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

stack<int> readStack(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}
void writeStack(stack<int>& s)
{
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    bool writespace = not s.empty();
    writeStack(s);
    if (writespace) cout << " ";
    cout << x;
}
#endif

int main()
{
    vector<stack<int> > v;
    vector<stack<int> > v12;
    string s;
    string x1, x2;
    int j = 0;
    while (getline(cin, s))
    {
        v.push_back(readStack(s));
        getline(cin, x1);
        v12.push_back(readStack(x1));
        getline(cin, x2);
        v12.push_back(readStack(x2));
    }
    for (int i = 0; i < int(v.size()); i++) {
        stack<int> s;
        s = reverse(v[i], v12[j].top(), v12[j + 1].top());
        writeStack(s); cout << endl;
        j = j + 2;
    }
}
