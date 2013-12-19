#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include <stdbool.h>
#include "file.h"
#include "outilsSaisie.h"

int main(){
	int choix, debut, fin;
	Graphe* graphe = NULL;

	printf("/************************************************/ \n");
	printf("\\*\t\t\t TP5 \t\t\t*\\\n");
	printf("/************************************************/ \n");

	printf("A partir de quel fichier voulez-vous charger votre graphe :\n");
	graphe = creerGraphe(saisieNomFichier());
	while(1)
	{
		printf("Choisissez ce que vous souhaitez faire : \n");
		printf("\t1 - Afficher les listes d'adjacences\n");
		printf("\t2 - Afficher la matrice d'adjacences\n");
		printf("\t3 - Afficher le parcours en largeur\n");
		printf("\t4 - Afficher le parcours en profondeur\n");
		printf("\t0 - Quitter le programme\n");

		choix = choixInt(5);
		printf("choix : %d\n", choix);
		switch(choix)
		{
			case 0:
				printf("Au revoir !\n");
				detruireGraphe(&graphe);
				return 1;
				break;
			case 1:
				afficherListesAdjacences(graphe);
				break;
			case 2:
				afficherMatriceAdjacences(graphe);
				break;
			case 3:
				printf("A partir de quel sommet voulez-vous afficher le parcours en largeur :\n");
				debut = choixInt(graphe->nbrSommet);
				printf("Vers quel sommet voulez-vous afficher le parcours en largeur :\n");
				fin = choixInt(graphe->nbrSommet);
				afficherChemin(graphe,graphe->tabSommet[debut],graphe->tabSommet[fin]);
				break;
			case 4:
				afficherParcoursProfondeur(graphe,graphe->tabSommet[debut]);
				break;
		}
	}

	return 1;
}