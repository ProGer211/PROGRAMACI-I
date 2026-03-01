#include <iostream>
#include <string>
#include <list>

using namespace std;


void balancear(list<int> &l, list<int> &l2)
{
	if (not(l.empty()) or not(l2.empty()))
	{
		while (l.size() > l2.size())
		{
			list<int>::iterator it = l.end();
			it--;
			int a = *it;
			l2.push_front(a);
			l.pop_back();
		}
		while (l2.size() > l.size())
		{
			list<int>::iterator it = l2.begin();
			int a = *it;
			l.push_back(a);
			l2.pop_front();
		}
		
	}
	
}

int main()
{
	list<int> l;
	list<int> l2;
	string command;
	while (cin >> command)
	{
		if (command == "push_front") {
			int x;
			cin >> x;
			l.push_front(x);
			balancear(l, l2);
		}
		else if (command == "push_back") {
			int x;
			cin >> x;
			l2.push_back(x);
			balancear(l, l2);
		}
		else if (command == "pop_front") {
			if (l.empty()) cout << "error" << endl;
			else l.pop_front();
			balancear(l, l2);

		}
		else if (command == "pop_back") {

			if (l2.empty() and l.empty()) cout << "error" << endl;
			else if (l2.empty() and not(l.empty())) l.pop_back();
			else l2.pop_back();
			balancear(l, l2);
		}
		else if (command == "get_mid_value") {
			if (l.empty()) cout << "error" << endl;
			else {
				if ((l.size()+ l2.size()) % 2 == 0)
				{
					cout << "error" << endl;
				}
				else
				{
					list<int>::iterator it = l.end();
					it--;
					int x = *it;
					cout << x << endl;
				}
			
			}
		}
	}
   
}

//get_mid_value el valor que esta en mig de la llista