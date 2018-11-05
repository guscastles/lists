SRC=src
ODIR=obj
LIB=lib
TDIR=test
INC=include
BIN=bin
LIB=lib
TODIR=$(ODIR)/test
_OBJ=list_creation.o list_removal.o list_transformation.o
_TOBJ=unittest.o test_list.o test_remove.o
LD_LIBRARY_PATH=$(HOME)/.local/lib
OBJ=$(patsubst %,$(ODIR)/%, $(_OBJ))
TOBJ=$(patsubst %,$(TODIR)/%, $(_TOBJ))
DEST=$(HOME)/.local

all: clean $(OBJ)

$(ODIR)/%.o: $(SRC)/%.c
	gcc $(DBG) -c -o $@ $< -iquote $(INC)/ 

.PHONY: tree
tree:
	tree

$(TODIR)/%.o: $(TDIR)/%.c
	gcc $(DBG) -c -o $@ $< -iquote $(INC)/

.PHONY: debug
debug:
	$(eval DBG=-g)

unittest: $(TOBJ) $(OBJ)
	gcc -o $(BIN)/$@ $^ -L$(DEST)/$(LIB) -llist -lcunit -I $(DEST)/$(INC)

debug_tests: debug unittest
	$(BIN)/unittest

run_tests: unittest
	$(BIN)/$<

static_lib: $(OBJ)
	ar rcs $(LIB)/liblist.a $<

install: static_lib
	cp $(LIB)/liblist.a $(DEST)/$(LIB)
	cp $(INC)/list.h $(DEST)/$(INC)

test_install: install
	gcc -o $(BIN)/listtest $(TDIR)/listtest.c -llist -I $(DEST)/include/ -L $(LD_LIBRARY_PATH)
	$(BIN)/listtest

.PHONY: uninstall
uninstall: 
	rm -f $(DEST)/$(LIB)/liblist.a
	rm -f $(DEST)/$(INC)/list.h

.PHONY: clean
clean: 
	rm -f $(BIN)/* $(ODIR)/*.o $(TODIR)/*
