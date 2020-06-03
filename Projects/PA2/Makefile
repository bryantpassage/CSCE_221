a.out: main.o
	g++ -Wall -o a.out main.o

main.o: main.cpp Node.h Deque.h
	g++ -c main.cpp

clean:
	rm -rf *.out
	rm -rf *.o

run:
	./a.out
