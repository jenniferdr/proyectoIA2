.PHONY = clean

SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)
DEP = $(SRC:.cc=.d)
CXXFLAGS = -g -MMD -std=c++0x -O2

othello: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

-include $(DEP)

clean:
	rm $(OBJ) $(DEP) othello
