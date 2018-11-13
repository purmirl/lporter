
all : lporter

lporter : main.o
	g++ -o lporter main.o -lpcap

main.o : main.cpp
	g++ -c -o main.o main.cpp -lpcap

clean :
	rm *.o lporter

