
all : lporter

lporter : main.o cui.o
	g++ -o lporter main.o cui.o -lpcap

main.o : main.cpp
	g++ -c -o main.o main.cpp -lpcap

cui.o : cui.h cui.cpp
	g++ -c -o cui.o cui.cpp

clean :
	rm *.o lporter

