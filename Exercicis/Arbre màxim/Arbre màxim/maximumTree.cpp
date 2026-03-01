#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

// Pre: Rep dos arbres binaris d'enters positius a1 i a2.
// Post: Retorna una arbre, on a la seva arrel hi ha el màxim de les arrels de a1,a2, després,
// en l'arrel del fill esquerra, el màxim de les arrels dels fills esquerra de a1,a2,
// i així successivament.
// Quan un dels arbres no té valors definits en alguna posició, l'arbre resultant hi té
// el valor de l'altre arbre en aquella posició.

void maximumTree_aux(BinaryTree<int>& a1, BinaryTree<int>& a2)
{
	if (a1.isEmpty() && a2.isEmpty()) return;
	else if (a1.isEmpty()) a1 = a2;
	else if (a2.isEmpty()) return;
	else
	{
		maximumTree_aux(a1.getLeft(), a2.getLeft());
		maximumTree_aux(a1.getRight(), a2.getRight());
		if (a2.getRoot() > a1.getRoot()) a1.getRoot() = a2.getRoot();

	}
}



BinaryTree<int> maximumTree(BinaryTree<int> a1, BinaryTree<int> a2)
{
	maximumTree_aux(a1, a2);
	return a1;
}