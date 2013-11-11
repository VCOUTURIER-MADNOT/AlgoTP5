#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphe.h"

	List** 	creerListeAdjacences(char * _fileName)
	{	
		List ** list = NULL;
		FILE * 	file = NULL;

		char* 	currentTag = (char *) malloc(sizeof(char)*50);
		char* 	currentTag2 = (char *) malloc(sizeof(char)*50);
		int		currentParam = 0;

		int nb1, nb2;
		cell cell1, cell2;

		file = fopen(_fileName, "r");

		if (file == NULL) return list;

		fscanf(file, "%s", currentTag);
		if (!strcmp(currentTag, "nSommets")
		{
			fscanf(file, "%d", &currentParam);
			if (currentParam > 0)
			{
				list = (List **) malloc(sizeof(List*) * currentParam);
			}
			currentParam = 0;
		}
		
		do
		{
			fscanf(file, "%s", currentTag);
		}while(strcmp(currentTag, "debDefAretes"));

		do
		{
			fscanf(file,"%s %s", currentTag, currentTag2);
			if(strcmp(currentTag, "finDefAretes") return list;
			nb1 = atoi(currentTag);
			cell1 = creerCellule(nb1);
			nb2 = atoi(currentTag2);
			cell2 = creerCellule(nb2);
			inserer(list[])
		}while(!feof(file));
	}

	void	afficherListeAdjacences(Graphe * _graphe)
	{

	}

	int**	creerMatriceAdjacences(char * _fileName)
	{

	}	

	void	afficherMatriceAdjacences(Graphe * _graphe)
	{

	}