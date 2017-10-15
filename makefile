.PHONY: all clean lib

INC=inc
SRC=src
OBJ=obj
DFLAGS=-DDEBUG
#DFLAGS=

all: dirs lib test

clean:
	rm $(OBJ)/*.o
	rm lib/*
	rm test

dirs:
	mkdir obj
	mkdir lib

test: $(OBJ)/main.o $(OBJ)/intType.o $(OBJ)/tPoint.o $(OBJ)/nAngle.o
	gcc -o test -L lib/ -larray $(OBJ)/main.o $(OBJ)/intType.o $(OBJ)/tPoint.o $(OBJ)/nAngle.o

lib: $(OBJ)/array.o
	gcc -shared -o lib/libarray.so $(OBJ)/array.o 

$(OBJ)/array.o: $(INC)/array.h $(SRC)/array.c
	gcc -c -I $(INC) -fPIC $(DFLAGS) -o $(OBJ)/array.o $(SRC)/array.c

$(OBJ)/main.o: $(INC)/array.h $(SRC)/main.c
	gcc -c -I $(INC) $(DFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/intType.o: $(INC)/intType.h $(SRC)/intType.c
	gcc -c -I $(INC) $(DFLAGS) -o $(OBJ)/intType.o $(SRC)/intType.c

$(OBJ)/tPoint.o: $(INC)/tPoint.h $(SRC)/tPoint.c
	gcc -c -I $(INC) $(DFLAGS) -o $(OBJ)/tPoint.o $(SRC)/tPoint.c

$(OBJ)/nAngle.o: $(INC)/nAngle.h $(INC)/tPoint.h $(SRC)/nAngle.c
	gcc -c -I $(INC) $(DFLAGS) -o $(OBJ)/nAngle.o $(SRC)/nAngle.c
