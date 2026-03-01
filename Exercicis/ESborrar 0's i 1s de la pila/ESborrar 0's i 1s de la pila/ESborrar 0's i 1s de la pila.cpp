

#include <iostream>
#include <stack>
#include <vector>
#include<string>
#include <sstream>

using namespace std;


void Remove01_aux(stack <int> &s)
{
	stack<int> copia = s;
	if (not(s.empty()))
	{
		int k = s.top();
		s.pop();
		copia.pop();
		Remove01_aux(s);
		if (k == 0 && copia.size() % 2 == 0) {
			copia.push(k);
			
		}
		else if (k == 1 && copia.size() % 2 != 0 && copia.size() != 0) {
			copia.push(k);
			
		}
		else {
			copia.push(k);
			s.push(k);
		
		}
	}
}

stack <int> remove01(stack <int>& s)
{
	Remove01_aux(s);
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
		cout << " " << t;
		rev.pop();
	}
}
