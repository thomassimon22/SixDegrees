CC = g++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = Queue.h NodeType.h LinkedList.h Stack.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

sixdegrees: main.o Graph.o Actor.o SixDegrees.o Queue.o Stack.o LinkedList.o 
	$(CC) -o sixdegrees main.o Graph.o Actor.o SixDegrees.o Queue.o Stack.o LinkedList.o

unittests: unittests.o Graph.o Actor.o SixDegrees.o Queue.o Stack.o LinkedList.o 
	$(CC) -o unittests unittests.o Graph.o Actor.o SixDegrees.o Queue.o Stack.o LinkedList.o

clean:
	rm -f *.o core* *~ sixdegrees