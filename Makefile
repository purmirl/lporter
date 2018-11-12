
all : lporter

lporter : main.o
	gcc -o lporter main.o -lpcap

main.o : main.cpp
	gcc -c -o main.o main.cpp -lpcap

clean :
	rm *.o lporter

