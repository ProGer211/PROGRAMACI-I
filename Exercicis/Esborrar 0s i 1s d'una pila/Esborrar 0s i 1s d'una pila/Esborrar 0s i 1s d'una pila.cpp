#include <iostream>
#include <stack>
#include <sstream>
#include<vector>
#include<string>

using namespace std;

#include <iostream>
#include <stack>

using namespace std;

void remove01_aux(stack<int>& s, int i)
{
	if (s.empty()) return;
	int a = s.top();
	s.pop();
	remove01_aux(s, i);
	if (a == 0)
	{
		if (i % 2 != 0) s.push(a);
	}
	else if (a == 1)
	{
		if (i % 2 == 0) s.push(a);
	}
	else s.push(a);
	i++;

}
stack<int> remove01(stack<int> s)
{
	int i = 0;
	remove01_aux(s, i);
	return s;
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
	stack<int> s;
	int a;
	while (cin >> a)
	{
		s.push(a);
	}
	s = remove01(s);
	stack<int> rev = reverse(s);
	while (not(rev.empty()))
	{
		int t = rev.top();
		cout << t << " ";
		rev.pop();
	}
}