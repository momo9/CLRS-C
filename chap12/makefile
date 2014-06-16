TAR=12-1-3.out
OBJ=treenode.o 12-1-3.o stack.o
FLAG=-Wall -g

$(TAR): $(OBJ)
	cc -o $(TAR) $(OBJ) $(FLAG)

12-1-3.o: treenode.h 12-1-3.c
	cc -c 12-1-3.c $(FLAG)

treenode.o: treenode.h stack.h treenode.c
	cc -c treenode.c $(FLAG)

stack.o: stack.h stack.c
	cc -c stack.c $(FLAG)

.PHONY: clean

clean:
	rm *.o *.out
