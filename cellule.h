#ifndef DEF_CELLULE
#define DEF_CELLULE

	typedef struct
	{
		struct Cell * previous;
		struct Cell * next;
		int word;
	} Cell;

	Cell * creerCellule(int _word);
	void detruireCellule(Cell ** _cell);

#endif