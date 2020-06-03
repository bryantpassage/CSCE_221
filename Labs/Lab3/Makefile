main.exe: main.o
	g++ -Wall -o main.exe main.o

main.o: main.cpp Point.h
	g++ -c -o main.o main.cpp

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe

run:
	./main.exe