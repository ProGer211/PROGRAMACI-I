#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

using namespace std;

bool parentesis(string line)
{
	istringstream mycin(line);
	char elem;
	stack<char> s;
	while (mycin >> elem)
	{
		if (elem == ')')
		{
			if (not (s.empty()))
			{
				char a = s.top();
				if (a == '(') s.pop();
			}
			else return false;
		}
		else if (elem == ']')
		{
			if (not (s.empty()))
			{
				char a = s.top();
				if (a == '[') s.pop();
			}
			else return false;

		}
		else
		{
			s.push(elem);
		}
	}
	if (s.empty()) return true;
	else return false;
}

int main()
{
	string line;

	while (cin >> line)
	{
		if (parentesis(line)) {
			cout << line + " is correct" << endl;
		}
		else
		{
			cout << line + " is incorrect" << endl;
		}

	}
}