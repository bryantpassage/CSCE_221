main.out: main.o
	g++ -Wall -o main.out main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm -f *.o
	rm -f *.out

run:
	./main.out