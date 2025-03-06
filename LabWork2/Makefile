PROJECT = mikmik
CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall
LGTESTFLAGS = -lgtest -lgtest_main -pthread

DEPS = $(wildcard *.hpp)

OBJ = Animatronic.o Cam.o Door.o Energy.o Fox.o Fredd.o Game.o Phone.o Player.o Random.o Picture.o Menu.o

.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

$(PROJECT): main.o $(OBJ)
	$(CXX) -o $@ main.o $(OBJ)

all: $(PROJECT)

docs:
	doxygen Doxyfile

.PHONY: clean cleanall

clean:
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT)
