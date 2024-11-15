CXX = g++
CXXFLAGS = -Wall -Wextra

main: main.o reversedata.o
	$(CXX) -o mik main.o reversedata.o

main.o: main.cpp reversedata.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

reversedata.o: reversedata.cpp reversedata.hpp
	$(CXX) $(CXXFLAGS) -c reversedata.cpp
	
clean:
	rm -f *.o mik

cleanall: clean
	rm -f *.tmp *.d *.log
