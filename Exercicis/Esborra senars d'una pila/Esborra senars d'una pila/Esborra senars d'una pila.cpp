

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> senars(stack<int> q)
{
    if (q.empty()) return q;
    if (not (q.empty()))
    {
        int k = q.top();
        q.pop();      
        q = senars(q);
        if (k % 2 != 0 && k != 0)
        {
            
            return q;
        }
        else
        {
            q.push(k);
            return q;
        }
    }
    
   

}
stack<int> reverse(stack<int> final)
{
    stack<int> rev;
    while (not(final.empty())) {
        rev.push(final.top());
        final.pop();
    }
    return rev;
}

int main()
{
    stack<int> q;
    int a;
    while (cin >> a) {
        q.push(a);

    }
    q = senars(q);
    stack<int> rev = reverse(q);
    while (not(rev.empty()))
    {
        int t = rev.top();
        cout << t << " ";
        rev.pop();
    }
}


