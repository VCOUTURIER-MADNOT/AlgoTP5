#include "cellule.h"
#include <stdlib.h>

Cell * creerCellule(int _word)
{
	Cell * cell;

	cell = (Cell *) malloc(sizeof(Cell));
	cell->word = _word;

	return cell;
}

void detruireCellule(Cell ** _cell)
{
	free(*_cell);
}