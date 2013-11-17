#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphe.h"
	
int main()
{
	Graphe * graphe = (Graphe *) malloc(sizeof(Graphe));

	creerListeAdjacences(graphe, "graphe1.txt");
	creerMatriceAdjacences(graphe, "graphe1.txt");
	afficherListeAdjacences(graphe);
	afficherMatriceAdjacences(graphe);
	return 1;
}