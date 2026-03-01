
#include <iostream>
#include <list>
#include<string>



using namespace std;

bool cua(list<int> l)
{
	if (not(l.empty()))
	{
		int i = 0;
		list<int>::iterator it = l.begin();
		list<int>::iterator it2 = l.end();
		if (l.size() == 1)
		{
			return false;
		}
		
		for (it2--; it != it2 ; it++)
		{	
			
			int t = *it;
			int k = *it2;
			if (*it != *it2) return false;	
			it2--;
			i++;
			if (l.size() % 2 == 0)
			{
				if (i == ((l.size()) / 2))
				{
					return true;
				}
			}
			
			
		}
		
	}
	return true;
	

}


int main()
{
	list<int> l;
	int a; 
	while (cin >> a)
	{
		l.push_back(a);
	}
	 bool encontrado = cua(l);
	 list<int>::iterator it = l.begin();
	 if (encontrado == true) {
		 cout << "Es capicua ";
		 for (; it != l.end(); it++)
		 {
			 int a = *it;
			 cout << *it << " ";

		 }
	 }
	 else {
		 cout << "No es capicua ";
		 for (; it != l.end(); it++)
		 {
			 int a = *it;
			 cout << *it << " ";

		 }
	 }


}

