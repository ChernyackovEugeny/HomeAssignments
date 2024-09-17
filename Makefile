CXX = g++
CXXFLAGS = -Wall -Wextra

main: main.o newhello.o
	$(CXX) -o hello main.o newhello.o

main.o: main.cpp heading.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

newhello.o: newhello.cpp heading.hpp
	$(CXX) $(CXXFLAGS) -c newhello.cpp

clean:
	rm -f *.o hello



