#ifndef CELL_H
#define CELL_H

class Cell {
	public:
		Cell();
			bool mine = false;
			bool revealed = false;
			bool marked = false;
			int otherMines = 0;
			char symbol;
			int update(int x, int y);
			
			protected:
			
			private:
};

#endif