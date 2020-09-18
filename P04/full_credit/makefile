 CXXFLAGS = --std=c++17

all: modulo

modulo: main.o *.h
	$(CXX) $(CXXFLAGS) main.o -o modulo
	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

modulo.gch: modulo.h
	$(CXX) $(CXXFLAGS) -c modulo.h -o modulo.gch

clean:
	rm -f *.o *.gch ~* a.out modulo
