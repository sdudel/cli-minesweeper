#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Cell.h"
using namespace std;

int number_of_mines = 3;
Cell board [6][6];

// Board layout
void baseBoard(int width, int height) {
    if (board[width][height].mine == false) {
        for (int xoff = -1; xoff <= 1; xoff++) {
             for (int yoff = -1; yoff <= 1; yoff++) {
                 if(board[width + xoff][height + xoff].mine == false && 
                 width + xoff <= 5 && 
                 width + xoff >= 0 && 
                 height + yoff >= 0 && 
                 height + yoff <= 5 && 
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
    
// Updates board piece
    for (int i = 0; i <=8; i++) {
         for (int j = 0; j <=8; j++) {
             if(board[i][j].update(i, j) == 1)
             baseBoard(i, j);
    }
}
    for (int i = 0; i <= 5; i++) {
         for (int j = 0; j <= 5; j++) {
             baseBoard(i, j);
    }
}
    cout << "    "; 		// 4 spaces before column start
    for (int i = 1; i <= 6; i++)
        cout << i << " "; 
        cout << "\n    "; 
        
    for (int i = 1; i <= 6; i++) 
        cout << "- "; 		//for each column, put a - under it.
        
    for (int width = 0; width <= 5; width++) { 
        cout << "\n " << width + 1 << "| "; 				//for each row, put a | beside it.
        for (int height = 0; height <= 5; height++){
            cout << board[width][height].symbol << " "; 	//space between each symbol
        }
    }
    cout << "\n";
}

int main() {
    srand(time(NULL));
    
//Randomize pieces
//------------------------------
    for (int i = 0; i < number_of_mines; i++) {
    int xpos = rand() % 6;
    int ypos = rand() % 6;

    if(board[xpos][ypos].mine == false) {
    	board[xpos][ypos].mine = true;
    	for (int xoff = -1; xoff <= 1; xoff++) {
    		for (int yoff = -1; yoff <= 1; yoff++) {
    			if (xpos + ypos <= 5 && xpos + ypos >= 0 && ypos + yoff >= 0 && ypos + yoff <= 5)
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
    
    cout << "\n\n\tEnter to expose, P to Flag >> "; 
    mode = getchar();
    mode = getchar();

        if (mode != 'P' && mode != 'p')  {
           if (x_coord <= 6 && x_coord >= 1 && y_coord <= 6 && y_coord >= 1)  {
    			if (board[x_coord - 1][y_coord - 1].mine == false) {
    			 	board[x_coord - 1][y_coord - 1].revealed = true; //reveal surrounding mines
    			 	
    			 for (int i = 0; i <= 5; i++) {
    			 		 for (int j = 0; j <= 5; j++) {
    			 		 	if (board[i][j].revealed == true && board[i][j].mine == false)
    			 		 	counter++;
    				 }
    			}
    		if (counter == 36 - number_of_mines) { // 6x6 board = 36 pieces
				 printBoard();
				 cout << "\n\n\tYOU WON!";
				 cout << "\n\tPress ENTER to exit game...";
				 getchar();
				 cout << endl;
				 exit(0);
			}
		}
	}
	            else {
    		         for (int width = 0; width <= 5; width++) {
    			        for (int height = 0; height <= 5; height++) {
    			        	if (board[width][height].mine == true) {
    			        		board[width][height].revealed = true;
    			        		board[width][height].update(width, height);
                    }
                }
            }
            	printBoard();
            	cout << "\n\n\tGAME OVER";
            	cout << "\n\tPress ENTER to exit game...";
            	getchar();
            	cout << endl;
           	 	exit(0);
        	}
    	}
    	
    	else if (mode == 'P' || mode =='p') {
    	if (board[x_coord - 1][y_coord - 1].marked == true)
    		board[x_coord - 1][y_coord - 1].marked = false;
    	else
    		board[x_coord - 1][y_coord - 1].marked = true;
		}
		printBoard();
  	}
}



