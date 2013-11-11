#ifndef DEF_GRAPHE
#define DEF_GRAPHE

	#include "liste.h"
	
	typedef struct
	{
		List** 		listeAdj;
		int** 		matriceAdj;
	} Graphe;

	List** 	creerListeAdjacences(char * _fileName);
	void	afficherListeAdjacences(Graphe * _graphe);
	int**	creerMatriceAdjacences(char * _fileName);
	void	afficherMatriceAdjacences(Graphe * _graphe);

#endif