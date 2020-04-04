CC=g++
CFLAGS=-c -Wall -Wpedantic

all: tvs

tvs: main.o g2t.o printNTree.o tvs.o
	$(CC) main.o g2t.o printNTree.o tvs.o -o tvs

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

g2t.o: ./src/g2t.cpp
	$(CC) $(CFLAGS) ./src/g2t.cpp

printNTree.o: ./src/printNTree.cpp
	$(CC) $(CFLAGS) ./src/printNTree.cpp

tvs.o: ./src/tvs.cpp
	$(CC) $(CFLAGS) ./src/tvs.cpp

clean:
	rm -rf *.o tvs