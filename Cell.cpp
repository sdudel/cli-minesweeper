#include "Cell.h"

Cell::Cell(){}

// Updates each cell on board with specific symbol
	int Cell::update(int width, int height) {
		if (revealed == false && marked == false)
			symbol = '-'; // default
		else if (revealed == true && mine == true)
			symbol = '@'; // MINE
		else if (revealed == true && marked == true)
			symbol = 'P'; // FLAG
		else if (otherMines > 0)
			symbol = otherMines + 48; //ascii 48 converts to 0
		else if (otherMines == 0) {
			symbol = ' '; // No adjacent mines
			return 1;
		}
	return 0;
}

