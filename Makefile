CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic -g3
DIR=src/
SRC=main.cc
S_SRC=$(addprefix $(DIR), $(SRC))
OBJ=$(S_SRC:.cc=.o)
BIN=test_flat_set

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(BIN)

.PHONY:all clean
