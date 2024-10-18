CXX = g++
CXXFLAGS = -Wall -Wextra

main: main.o pzapis.o
	$(CXX) -o pik main.o pzapis.o

main.o: main.cpp PZAPIS.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

pzapis.o: pzapis.cpp PZAPIS.hpp
	$(CXX) $(CXXFLAGS) -c pzapis.cpp

clean:
	rm -f *.o pik

cleanall: clean
	rm -f *.log *.tmp *.d
