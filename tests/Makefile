
all: bishop rook knight queen king pawn grid solitairchess
	echo "built all tests."
	./bishopTest
	./rookTest
	./knightTest
	./queenTest
	./kingTest
	./pawnTest
	./gridTest
	./solitairChessTest

bishop: prerequisits
	g++ bishoptest.cpp *.o -o bishopTest

rook: prerequisits
	g++ rooktest.cpp *.o -o rookTest

knight: prerequisits
	g++ knighttest.cpp *.o -o knightTest

queen: prerequisits
	g++ queentest.cpp *.o -o queenTest

king: prerequisits
	g++ kingtest.cpp *.o -o kingTest

pawn: prerequisits
	g++ pawntest.cpp *.o -o pawnTest

grid: prerequisits
	g++ gridtest.cpp *.o -o gridTest

solitairchess: prerequisits
	g++ solitairchesstest.cpp *.o -o solitairChessTest


prerequisits:
	cp ../*.o .
	rm main.o

clean:
	rm -f *.o
	rm -f bishopTest
	rm -f rookTest
	rm -f knightTest
	rm -f queenTest
	rm -f kingTest
	rm -f pawnTest	
	rm -f solitairChessTest
	rm -f gridTest
