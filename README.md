CLI Minesweeper Game - Project 1: 
----------------- 
Write a function which consumes three arguments, width, height, number_of_mines, and generates a Minesweeper board internally. The board is a rectangle with a cover over each square. It will display this board to the user and prompt for a coordinate where they predict that no mine exists (format: x-coord y-coord 0-indexed). If they struck a mine then they lose (let them know). Otherwise uncover the selected square. If there are no adjacent mines then it should be blank and you uncover all adjacent squares too (chain-react this for every blank square). Otherwise show the number of mines in the surrounding 8 squares. If at somepoint only mines are covered then the user wins and the game ends. 

POINTS: For every rule or rec from ARR and EXP that you include and document (external to the code) you get 20 points. Extra levels for (first click always blank) and the ability to flag mines.

Instructions:
----------------- 
To build the program: 
	
	$ make build
	
To run the program: 

	$ ./minesweeper

