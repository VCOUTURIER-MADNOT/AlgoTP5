#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"

Cellule* creerCellule(int valeur){

	Cellule* cellule =(Cellule*) malloc(sizeof(Cellule));
	cellule->cle=valeur;
	cellule->predecesseur = NULL;
	cellule->successeur = NULL;

	/*int i;
	for(i=0;i<taille;i++){
		cellule->cle[i]=chaine[i];
	}*/
	//stpcpy(cellule->cle,chaine);
	return cellule;
}

void detruireCellule(Cellule** cellule){
	//free((*cellule)->cle);
	(*cellule)->predecesseur=NULL;
	(*cellule)->successeur=NULL;
	(*cellule)=NULL;
	free(*cellule);
}
