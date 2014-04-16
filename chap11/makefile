TARGET = ex11.4-2.out
# OBJECTS = ex11.2-4.o tool.o hash_table.o node.o list.o
OBJECTS = ex11.4-2.o tool.o open_hash.o
$(TARGET): $(OBJECTS)
	cc -o $(TARGET) $(OBJECTS)

ex11.4-2o: tool.h open_hash.h
ex11.1-2.o: tool.h hash_table.h node.h
open_hash.o: open_hash.h tool.h
tool.o: tool.h
list.o: list.h node.h tool.h
node.o: node.h tool.h
hash_table.o: hash_table.h list.h tool.h

.PHONY: clean
clean:
	rm $(TARGET) $(OBJECTS)
