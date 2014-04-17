TARGET = ex12.2-3.out
TAR_OBJ = ex12.2-3.o
OBJECTS = $(TAR_OBJ) tool.o array_tree.o

$(TARGET): $(OBJECTS)
	cc -o $(TARGET) $(OBJECTS)

$(TAR_OBJ): tool.h array_tree.h
tool.o: tool.h
array_tree.o: array_tree.h tool.h 
