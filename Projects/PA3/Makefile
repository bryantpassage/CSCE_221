a.out: main.o
	g++ -Wall -o a.out main.o

main.o: main.cpp UnsortedPQ.h PriorityQueue.h SortedPQ.h HeapPQ.h
	g++ -c main.cpp

clean:
	rm -rf *.out
	rm -rf *.o

cleancsv:
	rm -rf *.csv

run:
	./a.out