#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool wellBracketed(string& s, int& i) 
{
	if (i == int(s.size())) return true;
	if (s[i] == '(') 
	{
		i++;
		if (not wellBracketed(s, i)) return false;
		if (i >= int(s.size())) return false;
		if (s[i] != ')') return false;
		i++;
		if (not wellBracketed(s, i)) return false;
	}
	
	if (s[i] == '[')
	{
		i++;
		if (not wellBracketed(s, i)) return false;
		if (i >= int(s.size())) return false;
		if (s[i] != ']') return false;
		i++;
		if (not wellBracketed(s, i)) return false;
	}
	
	if (s[i] == '{') 
	{
		i++;
		if (not wellBracketed(s, i)) return false;
		if (i >= int(s.size())) return false;
		if (s[i] != '}') return false;
		i++;
		if (not wellBracketed(s, i)) return false;
	}
	return true;
}

bool wellBracketed3(string s)
{
	int i = 0;
	if (not wellBracketed(s, i)) return false;
	return i == int(s.size());
}

int main() 
{
	string s;
	while (cin >> s)
		if (wellBracketed3(s)) cout << "Yes" << endl;
		else cout << "No" << endl;
}
 

