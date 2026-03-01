#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

stack<int> sumAboveOrBelow(stack<int>& sint, stack<string>& sstring)
{
    int a;
    while (not(sint.empty()) && not(sstring.empty()))
    {
        string com = sstring.top();
        if (com == "above")
        {
            int k = sint.top();
            sint.pop();
            sumAboveOrBelow(sint, sstring);
            a = a + k;
            sint.push(k);
            
        }
        else if (com == "below")
        {

        }
    }
}

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS
static stack<int> readStackInt(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}

static stack<string> readStackString(string line)
{
    istringstream mycin(line);
    stack<string> s;
    string x;
    while (mycin >> x)
        s.push(x);
    return s;
}

template <typename T>
static void writeStack(stack<T> s)
{
    vector<T> v;
    while (not s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    for (int i = int(v.size()) - 1; i >= 0; i--) {
        if (i < int(v.size()) - 1) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
#endif

int main() {
    vector<stack<int> > v;
    vector<stack<string> > vs;
    string s;
    while (getline(cin, s)) {
        v.push_back(readStackInt(s));
        getline(cin, s);
        vs.push_back(readStackString(s));
    }
    for (int i = 0; i < int(v.size()); ++i) {
        stack<int> s;
        for (int j = 0; j < 15; ++j)
            s = sumAboveOrBelow(v[i], vs[i]);
        writeStack(s);
    }
}
