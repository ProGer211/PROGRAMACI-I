

#include <iostream>
#include "BinaryTree.hpp"

using namespace std;


int altura(BinaryTree<int> &t)
{
    int r = 0;
    if (t.isEmpty()) r = 0;
    else if (t.getLeft().isEmpty()) r = 1;
    else
    {
        r = altura(t.getLeft());
    }
    return r;
}
int main()
{
    string s;
    while (cin >> s)
    {
        BinaryTree<int> t;
        readStringTree(s, t);
        cout << altura(t) << endl;
    }
}


