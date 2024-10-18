CXX = g++
CXXFLAGS = -Wall -Wextra

main: main.o dataf.o
	$(CXX) -o mik main.o dataf.o

main.o: main.cpp DATAF.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

dataf.o: dataf.cpp DATAF.hpp
	$(CXX) $(CXXFLAGS) -c dataf.cpp
	
clean:
	rm -f *.o mik

cleanall: clean
	rm -f *.tmp *.d *.log
