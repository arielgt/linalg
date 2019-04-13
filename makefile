CXX = g++-7
CFLAGS = -O3 -Wall

main : linalg.o main.o
	$(CXX) main.o linalg.o $(CFLAGS) -o main

linalg.o : linalg.cpp linalg.h
	$(CXX) linalg.cpp $(CFLAGS) -c -o linalg.o

main.o : main.cpp
	$(CXX) main.cpp $(CFLAGS) -c -o main.o

.PHONY: clean
clean : 
	rm *.o main	
