#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include "Cell.h"
using namespace std;

int number_of_mines = 3;
Cell board [9][9];
// int x = width and int y = height
void baseBoard(int x, int y) {
    if (board[x][y].mine == false) {
        for (int xoff = -1; xoff <= 1; xoff++) {
             for (int yoff = -1; yoff <= 1; yoff++) {
                 if(board[x + xoff][y + xoff].mine == false && 
                 x + xoff <= 8 && 
                 x + xoff >= 0 && 
                 y + yoff >= 0 && 
                 y + yoff <= 8 && 
                 board[x + xoff][y + xoff].revealed == false && 
                 board[x][y].otherMines == 0) {
                     board[x + xoff][y + xoff].revealed = true;
                     baseBoard(x + xoff, y + yoff);
                 }
             }
        }
    }
}

void printBoard() {
    system("clear");
    
// Updates board piece
    for (int i = 0; i <=8; i++) {
         for (int j = 0; j <=8; j++) {
             if(board[i][j].update(i, j) == 1)
             baseBoard(i, j);
    }
}
    for (int i = 0; i <= 8; i++) {
         for (int j = 0; j <= 8; j++) {
             baseBoard(i, j);
    }
}
    cout << "    "; // 4 spaces before column start
    for (int i = 1; i <= 9; i++)
        cout << i << " "; 
        cout << "\n    "; 
        
    for (int i = 1; i <= 9; i++) 
        cout << "- "; //for each column, put a _ under it.
        
    for (int x = 0; x <= 8; x++) { 
        cout << "\n " << x + 1 << "| "; //for each row, put a | beside it.
        for (int y = 0; y <= 8; y++){
            cout << board[x][y].symbol << " "; //space between each symbol
        }
    }
    cout << "\n";
}

int main() {
    srand(time(NULL));
    
//Randomize X and Y coordinates
//------------------------------
    for (int i = 0; i < number_of_mines; i++) {
    int xpos = rand() % 9;
    int ypos = rand() % 9;

    if(board[xpos][ypos].mine == false) {
    	board[xpos][ypos].mine = true;
    	for (int xoff = -1; xoff <= 1; xoff++) {
    		for (int yoff = -1; yoff <= 1; yoff++) {
    			if (xpos + ypos <=8 && xpos + ypos >= 0 && ypos + yoff >= 0 && ypos + yoff <= 8)
    			board[xpos + xoff][ypos + yoff].otherMines++;
    			}
    		}
    	}
    	else
    		i--;
    }

    printBoard();
    
// Select Coordinates
//------------------------------
    while (true) {
    int x_coord, y_coord, counter = 0;
    char mode;
    cout << "\n\n\tRow >> ";
    cin >> x_coord;
    cout << "\n\n\tColumn >> ";
    cin >> y_coord;
    cout << "\n\n\tEnter to expose, P to Flag:\n\n";
    mode = getchar();
    mode = getchar();
        if (mode != 'P' && mode != 'p')  {
           if (x_coord <= 9 && x_coord >= 1 && y_coord <= 9 && y_coord >= 1)  {
    			if (board[x_coord - 1][y_coord - 1].mine == false) {
    			 	board[x_coord - 1][y_coord - 1].revealed = true; //reveal surrounding mines
    			 	
    			 for (int i = 0; i <= 8; i++) {
    			 		 for (int j = 0; j <= 8; j++) {
    			 		 	if (board[i][j].revealed == true && board[i][j].mine == false)
    			 		 	counter++;
    				 }
    			}
    		if (counter == 81 - number_of_mines) { // 9x9 board = 81 pieces
				 printBoard();
				 cout << "\n\n\tYOU WON!";
				 cout << "\n\tPress ENTER to exit game....";
				 getchar();
				 cout << endl;
				 exit(0);
			}
		}
	}
	            else {
    		         for (int x = 0; x <= 8; x++) {
    			        for (int y = 0; y <= 8; y++) {
    			        	if (board[x][y].mine == true) {
    			        		board[x][y].revealed = true;
    			        		board[x][y].update(x, y);
                    }
                }
            }
            	printBoard();
            	cout << "\n\n\tGAME OVER";
            	cout << "\n\tPress ENTER to exit game....";
            	getchar();
            	cout << endl;
           	 	exit(0);
        	}
    	}
    	
    	else if (mode == 'P' || mode =='p') {
    	if (board[x_coord-1][y_coord-1].marked == true)
    		board[x_coord-1][y_coord-1].marked = false;
    	else
    		board[x_coord-1][y_coord-1].marked = true;
		}
		printBoard();
  	}
}



