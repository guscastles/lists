SRC=src
OBJ=obj
TST=tst
TST_OBJ=obj/tst
OBJ_FILES=list_creation.o list_removal.o list_transformation.o
TST_OBJ_FILES=unittest.o test_list.o test_remove.o
HDR=hdr
BIN=bin
LIB=lib
LD_LIBRARY_PATH=$(HOME)/.local/lib
ODIR=$(patsubst %,$(OBJ)/%, $(OBJ_FILES))
TODIR=$(patsubst %,$(TST_OBJ)/%, $(TST_OBJ_FILES))
DEST=$(HOME)/.local/$(LIB)

all: clean $(ODIR)

$(OBJ)/%.o: $(SRC)/%.c
	gcc -c -o $@ $< -iquote $(HDR)/ 

clean: 
	rm -f $(BIN)/* $(OBJ)/*.o $(TST_OBJ)/*

.PHONY: tree
tree:
	tree

$(TST_OBJ)/%.o: $(TST)/%.c
	gcc -g -c -o $@ $< -iquote $(HDR)/

install: static_lib
	cp $(OBJ)/liblist.a $(DEST)

unittest: $(TODIR)
	gcc -o $(BIN)/$@ $^ -L$(DEST) -llist -lcunit

run_tests: unittest
	$(BIN)/$<

static_lib: $(ODIR)
	ar rcs $(OBJ)/liblist.a $^

uninstall: liblist.a
	rm -f $(DEST)/$<

