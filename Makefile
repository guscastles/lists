SRC=src
OBJ=obj
TST=tst
TST_OBJ=obj/tst
OBJ_FILES=list.o
TST_OBJ_FILES=unittest.o test_list.o test_remove.o
HDR=hdr
BIN=bin
LIB=lib
ODIR=$(patsubst %,$(OBJ)/%, $(OBJ_FILES))
TODIR=$(patsubst %,$(TST_OBJ)/%, $(TST_OBJ_FILES))
DEST=$(HOME)/.local/$(LIB)

all: clean obj/list.o

$(OBJ)/%.o: $(SRC)/%.c
	gcc -c -o $@ $< -iquote $(HDR)/ 

clean: 
	rm -f $(BIN)/* $(OBJ)/*.o $(TST_OBJ)/*

.PHONY: tree
tree:
	tree

$(TST_OBJ)/%.o: $(TST)/%.c
	gcc -g -c -o $@ $< -iquote $(HDR)/

unittest: $(TODIR) $(OBJ)/list.o
	gcc -o $(BIN)/$@ $^ -lcunit

run_tests: unittest
	$(BIN)/$<

install: $(OBJ)/$(OBJ_FILES)
	cp $< $(DEST)/

uninstall: obj/list.o
	rm -f $(DEST)/$<

