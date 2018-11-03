SRC=src
OBJ=obj
TST=tst
TST_OBJ=obj/tst
OBJ_FILES=list.o run_list.o
TST_OBJ_FILES=unittest.o test_list.o
HDR=hdr
BIN=bin
ODIR=$(patsubst %,$(OBJ)/%, $(OBJ_FILES))
TODIR=$(patsubst %,$(TST_OBJ)/%, $(TST_OBJ_FILES))
DEST=$(HOME)/.local/bin

all: clean run_list

$(OBJ)/%.o: $(SRC)/%.c
	gcc -c -o $@ $< -I $(HDR)/ 

run_list: $(ODIR)
	gcc -o $(BIN)/$@ $^

run: run_list install
	$<

clean: 
	rm -f $(BIN)/* $(OBJ)/*.o $(TST_OBJ)/*

.PHONY: tree
tree:
	tree

$(TST_OBJ)/%.o: $(TST)/%.c
	gcc -g -c -o $@ $< -I $(HDR)/

unittest: $(TODIR) $(OBJ)/list.o
	gcc -o $(BIN)/$@ $^ -lcunit

run_tests: unittest
	$(BIN)/$<

install: run_list
	cp $(BIN)/$< $(DEST)/

uninstall: run_list
	rm -f $(DEST)/$<

