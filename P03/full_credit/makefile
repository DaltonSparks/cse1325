CXXFLAGS += --std=c++17

all: game

game: main.o board.o tile.o *.h
	$(CXX) $(CXXFLAGS) main.o board.o tile.o -o game

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

board.o: board.cpp *.h
	$(CXX) $(CXXFLAGS) -c board.cpp -o board.o

tile.o: tile.cpp *.h
	$(CXX) $(CXXFLAGS) -c tile.cpp -o tile.o

tile.gch: tile.h
	$(CXX) $(CXXFLAGS) -c tile.h -o tile.gch

board.gch: board.h
	$(CXX) $(CXXFLAGS) -c board.h -o board.gch



clean:
	rm -f *.o *.gch ~* a.out game
