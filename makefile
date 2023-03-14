CXX=gcc
#CXXFLAGS=-Isrc -Wall -O3 -c
CXXFLAGS=-Isrc -Wall -g -c
OBJDIR=lib
OBJ=$(OBJDIR)/binary_search_tree.o $(OBJDIR)/main.o
EXE=binary-search-tree

.PHONY: all clean

all: $(EXE)

binary-search-tree: $(OBJ)
	$(CXX) -o $@ $^

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(EXE)
