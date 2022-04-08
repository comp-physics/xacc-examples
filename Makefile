CXX=g++
CXXFLAGS=-g -std=c++17 -pedantic -Wall -Wextra -Werror
EXAMPLES=xx_xacc bell

.DUMMY: all clean

all: $(EXAMPLES)

bell: bell.o
	$(CXX) $^ -lxacc -o $@

xx_xacc: xx_xacc.o
	$(CXX) $^ -lxacc -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -vf $(wildcard *.o) $(EXAMPLES)
