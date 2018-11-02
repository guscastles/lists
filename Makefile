SRC=src
OBJ=obj
OBJ_FILES=list.o run_list.o
HDR=hdr
BIN=bin
ODIR=$(patsubst %,$(OBJ)/%, $(OBJ_FILES))

all: run_list

$(OBJ)/%.o: $(SRC)/%.c
	gcc -c -o $@ $< -I $(HDR)/ 

run_list: $(ODIR)
	gcc -o $(BIN)/$@ $^

run: run_list
	$(BIN)/$<

clean: 
	rm -f $(BIN)/* $(OBJ)/*

.PHONY:
	tree

test_remove: tst/test_remove.c src/list.c
	rm bin/$@; gcc -o $(BIN)/$@ $^ -I $(HDR)/;$(BIN)/$@
