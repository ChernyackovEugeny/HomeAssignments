CXX = g++
CXXFLAGS = -Wall -Wextra

main: Transformer.o Deceptikon.o Bbee.o Autobots.o main.o Gun.o Hp.o
	$(CXX) -o mikmik Transformer.o Deceptikon.o Bbee.o Autobots.o main.o Gun.o Hp.o
	
test: Transformer.o Deceptikon.o Bbee.o Autobots.o Gun.o Hp.o tests.cpp
	$(CXX) $(CXXFLAGS) -o testik tests.cpp Transformer.o Deceptikon.o Bbee.o Autobots.o Gun.o Hp.o -lgtest -lgtest_main -pthread

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Gun.o: Gun.cpp Gun.hpp
	$(CXX) $(CXXFLAGS) -c Gun.cpp

Hp.o: Hp.cpp Hp.hpp
	$(CXX) $(CXXFLAGS) -c Hp.cpp

Transformer.o: Transformer.cpp Transformer.hpp Gun.hpp Hp.hpp
	$(CXX) $(CXXFLAGS) -c Transformer.cpp

Deceptikon.o: Deceptikon.hpp Deceptikon.cpp
	$(CXX) $(CXXFLAGS) -c Deceptikon.cpp
    
Bbee.o: Bbee.cpp Bbee.hpp
	$(CXX) $(CXXFLAGS) -c Bbee.cpp

Autobots.o: Autobots.cpp Autobots.hpp
	$(CXX) $(CXXFLAGS) -c Autobots.cpp

clean:
	rm -f *.o mikmik

cleanall: clean
	rm -f *.log *.d *.tmp testik


