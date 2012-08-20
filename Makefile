
all:
	g++ -c *.cpp -Wall -ansi -pedantic
	g++ *.o -o chess

clean:
	rm -f chess
	rm -f *.o
