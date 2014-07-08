CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic -g3
DIR=src/
SRC=main.cc
S_SRC=$(addprefix $(DIR), $(SRC))
OBJ=$(S_SRC:.cc=.o)
OBJ2=$(src/bench:.cc=.o)
BIN=test_flat_set

all: $(BIN)

src/bench/benchmark.o: src/bench/benchmark.cc
	$(CXX) $(CXXFLAGS) -O3 -c -o $@ $< 

bench: src/bench/benchmark.o
	$(CXX) $(CXXFLAGS) -O3 $^ -o $@

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(BIN)

.PHONY:all clean
