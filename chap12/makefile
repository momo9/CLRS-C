TARGET = ex12.3-1.out
TAR_OBJ = ex12.3-1.o
OBJECTS = $(TAR_OBJ) tree_node.o ptr_tree.o

$(TARGET): $(OBJECTS)
	cc -o $(TARGET) $(OBJECTS) -lstdc++

$(TAR_OBJ): tool.h ptr_tree.h
ptr_tree.o: ptr_tree.h tree_node.h
tree_node.o: tree_node.h
tool.o: tool.h
array_tree.o: array_tree.h tool.h 
