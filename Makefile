CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic -g3
DIR=src/
SRC=base.cc integer.cc uplus.cc plus.cc minus.cc star.cc slash.cc parser.cc \
    integer.cc uminus.cc input.cc operations.cc utils.cc main.cc
S_SRC=$(addprefix $(DIR), $(SRC))
OBJ=$(S_SRC:.cc=.o)
BIN=bistromathique

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(BIN)

.PHONY:all clean
