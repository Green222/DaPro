CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic -fPIC -g3 -I/usr/include/python2.7
DIR=src/
SRC=main.cc
S_SRC=$(addprefix $(DIR), $(SRC))
OBJ=$(S_SRC:.cc=.o)
BIN=test_flat_set
LIBA=libbind.a
LIBSO=libbind.so

all: $(BIN) $(LIBA) $(LIBSO)

$(LIBA): $(OBJ)
	ar csr $@ $(OBJ)

$(LIBSO): $(OBJ)
	$(CXX) -shared -o $@ $(OBJ)

src/bench/benchmark.o: src/bench/benchmark.cc
	$(CXX) $(CXXFLAGS) -O3 -c -o $@ $< 

bench: src/bench/benchmark.o
	$(CXX) $(CXXFLAGS) -O3 $^ -o $@

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

export:
	git archive HEAD --prefix=guet_e-pruvot_a-CXXA/ \
	| bzip2 > guet_e-pruvot_a-CXXA.tar.bz2

clean:
	$(RM) $(OBJ)
	$(RM) $(BIN)
	$(RM) $(LIBA)
	$(RM) bench
	$(RM) src/bench/benchmark.o

.PHONY:all clean
