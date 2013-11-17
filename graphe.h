#ifndef DEF_GRAPHE
#define DEF_GRAPHE

	#include "liste.h"
	
	typedef struct
	{
		int			nbSommets;
		List** 		listeAdj;
		int** 		matriceAdj;
	} Graphe;

	void 	creerListeAdjacences(Graphe * _graphe, char * _fileName);
	void	afficherListeAdjacences(Graphe * _graphe);
	void	creerMatriceAdjacences(Graphe * _graphe, char * _fileName);
	void	afficherMatriceAdjacences(Graphe * _graphe);

#endif