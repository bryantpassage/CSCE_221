a.out: driver.o ArrayStack.o DoubleArrayStack.o LinkedList.o
	g++ -o a.out -Wall driver.o ArrayStack.o DoubleArrayStack.o LinkedList.o

driver.o: driver.cpp ArrayStack.cpp DoubleArrayStack.cpp LinkedList.cpp
	g++ -c driver.cpp

ArrayStack.o: ArrayStack.cpp Stack.h
	g++ -c ArrayStack.cpp

DoubleArrayStack.o: DoubleArrayStack.cpp Stack.h
	g++ -c DoubleArrayStack.cpp

LinkedList.o: LinkedList.cpp Stack.h
	g++ -c LinkedList.cpp

clean:
	rm -rf *.out
	rm -rf *.o
cleanout:
	rm -rf *.csv

run:
	./a.out