PROJECT = mikmik
CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall
LGTESTFLAGS = -lgtest -lgtest_main -pthread

DEPS = $(wildcard *.hpp)

OBJ = Animatronic.o Cam.o Door.o Energy.o Fox.o Fredd.o Game.o Phone.o Player.o Random.o

.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

$(PROJECT): main.o $(OBJ)
	$(CXX) -o $@ main.o $(OBJ)

all: $(PROJECT)


.PHONY: clean cleanall

clean:
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT)
