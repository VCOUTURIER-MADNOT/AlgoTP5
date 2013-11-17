#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphe.h"
#include "liste.h"

	void creerListeAdjacences(Graphe * _graphe, char * _fileName)
	{	
		List ** list = NULL;
		FILE * 	file = NULL;

		char* 	currentTag = (char *) malloc(sizeof(char)*50);
		int 	currentTag2;
		int		currentParam = 0;
		int		j, i;

		Cell *cell1, *cell2;

		file = fopen(_fileName, "r");

		if (file == NULL) return;

		fscanf(file, "%s", currentTag);
		if (!strcmp(currentTag, "nSommets"))
		{
			fscanf(file, "%d", &currentParam);
			if (currentParam > 0)
			{
				_graphe->nbSommets = currentParam;
				list = (List **) malloc(sizeof(List*) * _graphe->nbSommets);
			}
		}

		for(i =0; i<_graphe->nbSommets; i++)
		{
			list[i] = creerListe();
		}

		do
		{
			fscanf(file, "%s", currentTag);
		}while(strcmp(currentTag, "debutDefAretes"));

		do
		{
			fscanf(file,"%s %d", currentTag, &currentTag2);
			if(strcmp(currentTag, "finDefAretes"))
			{
				printf("%d %d \n", atoi(currentTag), currentTag2);
				cell2 = creerCellule(currentTag2);
				inserer(list[atoi(currentTag)], cell2);
			}
		}while(!feof(file));

		_graphe->listeAdj = list;
	}

	void	afficherListeAdjacences(Graphe * _graphe)
	{
		int i,j;

		for (i = 0; i<_graphe->nbSommets; i++)
		{
			Cell * cell = NULL;
			printf("Liste: %d \n", i);

			j = 0;
			cell = _graphe->listeAdj[i]->cell;
			if(cell == NULL)
			{
				printf("La liste est vide !\n");
			}
			while(cell != NULL)
			{
				printf("Element numéro %d : %d\n", j++, cell->word);
				cell = cell->next;
			}
		}
	}

	void	creerMatriceAdjacences(Graphe * _graphe, char * _fileName)
	{
		char* 	currentTag = (char *) malloc(sizeof(char)*50);
		int 	currentTag2;
		FILE * 	file = NULL;
		file = fopen(_fileName, "r");
		int** matrice = NULL;
		int i;

		matrice = (int**) malloc(sizeof(int*) * _graphe->nbSommets);

		if (file == NULL) return;

		do
		{
			fscanf(file, "%s", currentTag);
		}while(strcmp(currentTag, "debutDefAretes"));

		for(i =0; i<_graphe->nbSommets; i++)
		{
			matrice[i] = (int*) malloc(sizeof(int) * _graphe->nbSommets);
			memset(matrice[i], 0, sizeof(int) * _graphe->nbSommets);
		}

		do
		{
			fscanf(file,"%s %d", currentTag, &currentTag2);
			if(strcmp(currentTag, "finDefAretes"))
			{
				matrice[atoi(currentTag)][currentTag2] = 1;
				matrice[currentTag2][atoi(currentTag)] = 1;
			}
		}while(!feof(file));

		_graphe->matriceAdj = matrice;
	}	

	void	afficherMatriceAdjacences(Graphe * _graphe)
	{
		int i, j;
		for(i = 0; i<_graphe->nbSommets; i++)
		{
			for (j= 0; j < _graphe->nbSommets; ++j)
			{
				printf("%d ", _graphe->matriceAdj[i][j]);
			}
			printf("\n");
		}
	}