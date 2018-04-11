#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Cell.h"

using namespace std;

Cell board [9][9];
int number_of_mines = 3;

// Board layout
void baseBoard(int width, int height) {
    if (board[width][height].mine == false) {
        for (int xoff = -1; xoff <= 1; xoff++) {
             for (int yoff = -1; yoff <= 1; yoff++) {
                 if(board[width + xoff][height + xoff].mine == false && 
                 width + xoff <= 8 && 
                 width + xoff >= 0 && 
                 height + yoff >= 0 && 
                 height + yoff <= 8 && 
                 board[width + xoff][height + xoff].revealed == false && 
                 board[width][height].otherMines == 0) {
                     board[width + xoff][height + xoff].revealed = true;
                     baseBoard(width + xoff, height + yoff);
                 }
             }
        }
    }
}

void printBoard() {
    system("clear");
    
// Game board Layout 
    for (int i = 0; i <= 8; i++) {
         for (int j = 0; j <= 8; j++) {
             if(board[i][j].update(i, j) == 1)
             baseBoard(i, j);
    }
}
    for (int i = 0; i <= 8; i++) {
         for (int j = 0; j <= 8; j++) {
             baseBoard(i, j);
    }
}
    cout << "    "; 		// 4 spaces before column start
    for (int i = 1; i <= 9; i++)
        cout << i << " "; 
        cout << "\n    "; 
        
    for (int i = 1; i <= 9; i++) 
        cout << "- ";		//for each column, put a - under it.
        
    for (int width = 0; width <= 8; width++) { 
        cout << "\n " << width + 1 << "| ";		//for each row, put a | beside it.
        for (int height = 0; height <= 8; height++){
            cout << board[width][height].symbol << " ";		//space between each symbol
        }
    }
    cout << newline;
}

int main() {
    srand(time(NULL));
    
//Randomize pieces
    for (int i = 0; i < number_of_mines; i++) {
    int xpos = rand() % 9;
    int ypos = rand() % 9;

    if(board[xpos][ypos].mine == false) {
    	board[xpos][ypos].mine = true;
    	for (int xoff = -1; xoff <= 1; xoff++) {
    		for (int yoff = -1; yoff <= 1; yoff++) {
    			if (xpos + ypos <= 8 && xpos + ypos >= 0 && ypos + yoff >= 0 && ypos + yoff <= 8)
    			board[xpos + xoff][ypos + yoff].otherMines++;
    			}
    		}
    	}
    	else
    		i--;
    }

    printBoard();
    
// Select Coordinates
    while (true) {
    int x_coord, y_coord, counter = 0;
    char mode;

    cout << newline << newline << "\tColumn >> ";
    cin >> y_coord;
    cout << newline << newline << "\tRow >> ";
    cin >> x_coord;
    
    cout << newline << newline << "\tEnter to expose, P to Flag >> "; 
    mode = getchar();
    mode = getchar();
    
// Reveal surrounding mines
        if (mode != 'P' && mode != 'p')  {
           if (x_coord <= 9 && x_coord >= 1 && y_coord <= 9 && y_coord >= 1)  {
    			if (board[x_coord - 1][y_coord - 1].mine == false) {
    			 	board[x_coord - 1][y_coord - 1].revealed = true; 	
    			 for (int i = 0; i <= 8; i++) {
    			 		 for (int j = 0; j <= 8; j++) {
    			 		 	if (board[i][j].revealed == true && board[i][j].mine == false)
    			 		 	counter++;
    				 }
    			}
    			
// User WON - Exit Game
    		if (counter == 81 - number_of_mines) { 	// 9x9 board = 81 pieces
				 printBoard();
				 cout << newline << newline << "\tYOU WON!";
				 cout << newline << newline << "\tPress ENTER to exit game...";
				 cout << newline;
				 getchar();
				 cout << endl;
				 exit(0);
			}
		}
	}
	
// Mine Revealed - User LOST
	            else {
    		         for (int width = 0; width <= 8; width++) {
    			        for (int height = 0; height <= 8; height++) {
    			        	if (board[width][height].mine == true) {
    			        		board[width][height].revealed = true;
    			        		board[width][height].update(width, height);
                    }
                }
            }
// Game Over - Exit Game    
            	printBoard();
            	cout << newline << newline << "\tGAME OVER";
            	cout << newline << newline << "\tPress ENTER to exit game...";
            	cout << newline;
            	getchar();
            	cout << endl;
           	 	exit(0);
        	}
    	}
    	
// Flag cells on board
    	else if (mode == 'P' || mode =='p') {
    	if (board[x_coord - 1][y_coord - 1].marked == true)
    		board[x_coord - 1][y_coord - 1].marked = false;
    	else
    		board[x_coord - 1][y_coord - 1].marked = true;
		}
		printBoard();
  	}
}



