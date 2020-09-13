OBJS	= main.o board.o tile.o
SOURCE	= main.cpp board.cpp tile.cpp
HEADER	= board.h tile.h
OUT	= game
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++17

board.o: board.cpp
	$(CC) $(FLAGS) board.cpp -std=c++17

tile.o: tile.cpp
	$(CC) $(FLAGS) tile.cpp -std=c++17


clean:
	rm -f *.o *.gch ~* a.out game
