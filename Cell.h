#ifndef CELL_H
#define CELL_H
#define newline '\n'

class Cell {
	public:
		Cell();
			bool mine = false;
			bool revealed = false;
			bool marked = false;
			int otherMines = 0;
			char symbol;
			int update(int width, int height);
			protected:
			private:
};
#endif