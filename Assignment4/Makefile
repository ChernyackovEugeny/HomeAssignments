PROJECT = mikmik
CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall
LGTESTFLAGS = -lgtest -lgtest_main -pthread

DEPS = $(wildcard *.hpp)

OBJ = Autobots.o Bbee.o Deceptikon.o Gun.o Hp.o Transformer.o
TEST_OBJ = tests.o

TEST_PROJECT = testik


.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

$(PROJECT): main.o $(OBJ)
	$(CXX) -o $@ main.o $(OBJ)

$(TEST_PROJECT): $(TEST_OBJ) $(OBJ)
	$(CXX) -o $@ $(TEST_OBJ) $(OBJ) $(LGTESTFLAGS)

all: $(PROJECT)

test: $(TEST_PROJECT)


.PHONY: clean cleanall

clean:
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT)
	rm -f $(TEST_PROJECT)
