
build: 
	g++ -Wall -std=c++11 -c mine.cpp -o objects/mine.o 
	g++ -Wall -std=c++11 -c Cell.cpp -o objects/Cell.o 
	g++ -Wall -std=c++11 -g -o minesweeper objects/*.o 
 
clean:
	rm -f objects/*.o minesweeper