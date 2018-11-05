SRC=src
OBJ=obj
LIB=lib
# DEBUG= Set the environment variable with export command
# export DEBUG=-g
TST=test
TST_OBJ=$(OBJ)/$(TST)
OBJ_FILES=list_creation.o list_removal.o list_transformation.o
TST_OBJ_FILES=unittest.o test_list.o test_remove.o
INC=include
BIN=bin
LIB=lib
LD_LIBRARY_PATH=$(HOME)/.local/lib
ODIR=$(patsubst %,$(OBJ)/%, $(OBJ_FILES))
TODIR=$(patsubst %,$(TST_OBJ)/%, $(TST_OBJ_FILES))
DEST=$(HOME)/.local/$(LIB)
DEST_INC=$(HOME)/.local/$(LIB)

all: clean $(ODIR)

$(OBJ)/%.o: $(SRC)/%.c
	gcc $(DEBUG) -c -o $@ $< -iquote $(INC)/ 

.PHONY: tree
tree:
	tree

$(TST_OBJ)/%.o: $(TST)/%.c
	gcc $(DEBUG) -c -o $@ $< -iquote $(INC)/

unittest: $(TODIR) $(ODIR)
	gcc -o $(BIN)/$@ $^ -L$(DEST) -llist -lcunit

run_tests: unittest
	$(BIN)/$<

static_lib: $(ODIR)
	ar rcs $(LIB)/liblist.a $^

install: static_lib
	cp $(LIB)/liblist.a $(DEST)
	cp $(INC)/list.h $(DEST_INC)

.PHONY: uninstall
uninstall: 
	rm -f $(DEST)/liblist.a
	rm -f $(DEST_INC)/list.h

.PHONY: clean
clean: 
	rm -f $(BIN)/* $(OBJ)/*.o $(TST_OBJ)/*
