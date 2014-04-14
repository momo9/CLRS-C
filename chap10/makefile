TARGET = ex10.4-2.out
# OBJECTS = ex10.3-5.o tool.o
OBJECTS = ex10.4-2.o tool.o link_tree.o
# OBJECTS = ex10.2-6.o list.o node.o tool.o
$(TARGET): $(OBJECTS)
	cc -o $(TARGET) $(OBJECTS)

ex10.4-2.o: link_tree.h
ex10.3-5.o: tool.h
ex10.3-4.o: tool.h
ex10.2-4.o: list.h tool.h node.h
ex10.2-6.o: list.h tool.h node.h
link_tree.o: link_tree.h
tool.o: tool.h
list.o: list.h tool.h
node.o: node.h tool.h

.PHONY: clean
clean:
	rm $(TARGET) $(OBJECTS)
