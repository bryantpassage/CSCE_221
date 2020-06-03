a.out: driver.o Sorts.o 
	g++ -Wall -o a.out driver.o Sorts.o

driver.o: driver.cpp Sorts.h
	g++ -c driver.cpp

Sorts.o: Sorts.cpp Sorts.h Heap.h
	g++ -c Sorts.cpp

clean:
	rm -rf *.out
	rm -rf *.o

cleancsv:
	rm -rf *.csv
	
run:
	./a.out