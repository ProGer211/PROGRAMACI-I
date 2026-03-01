#include <iostream>


using namespace std;
#include "copyEvenPos.hpp"


// Pre:  pitem apunta al primer element d'una seqüència correcta d'items encadenats.
//       L'últim element de la seqüència apunta a NULL. El propi pitem podria ser NULL,
//       cas en el qual no hi hauria elements a la seqüència.
// Post: Retorna un Item* que representa una seqüència d'items nous tals que la seva
//       corresponent seqüència de valors és una còpia de la subseqüencia de valors
//       a posició parell de la seqüència original.
//       La seqüència de valors original no ha canviat.
void copyEvenPos_aux(Item* &pitem)
{	
	if (pitem == NULL) return;
	if (pitem->next == NULL) return;
	Item* pitem1 = pitem;
	pitem = pitem->next;
	Item* ppitem = pitem;
	copyEvenPos_aux(pitem);
	if (pitem1->value >= ppitem->value)
	{
		ppitem->next = pitem1;
		pitem1->next = NULL;
	}
	else
	{
		ppitem->next = pitem1;
		

	}
	
							
}
Item* copyEvenPos(Item* pitem)
{
     copyEvenPos_aux(pitem);
	return pitem;
}