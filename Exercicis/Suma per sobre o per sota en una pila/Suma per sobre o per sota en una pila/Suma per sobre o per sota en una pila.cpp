#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

void sumAboveOrBelowRec(stack<int>& sint, stack<string> sstring, stack<int>& f, int d, int& i, string& s)
{
    if (sint.empty()) return;
    string b = sstring.top();
    sstring.pop();
    if (i == sstring.size()) s = b;
    int a = sint.top();
    sint.pop();
    sumAboveOrBelowRec(sint, sstring, f, d, i, s);
    if (s == "above")
    {
        if (f.empty()) f.push(a);
        else if (f.size() == i) f.push(a);
        else if (i <= sint.size())
        {
            int c = f.top();
            f.pop();
            f.push(c + a);
        }
        sint.push(a);
    }
    if (s == "below")
    {
        if (f.empty())
        {
            f.push(a);
        }
        else if (f.size() == i) f.push(a);
        else if (i >= sint.size())
        {
        
            int c = f.top();
            f.pop();
            f.push(c + a);
        }
        sint.push(a);
    }
    if (d == sint.size())
    {
        i++;
        sstring.push(b);
        if (sint.size() == f.size()) return;
        else sumAboveOrBelowRec(sint, sstring, f, d, i, s);
    }

}

stack<int> sumAboveOrBelow(stack<int> sint, stack<string> sstring)
{
    stack<int> f;
    int i = 0;
    int d = sint.size();
    string s;
    sumAboveOrBelowRec(sint, sstring, f, d, i, s);
    return f;
}


stack<int> sumAboveOrBelow(stack<int> sint, stack<string> sstring);

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