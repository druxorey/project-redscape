CC=g++
CFLAGS=-I include
OBJS= main.o cards.o cutscenes.o

all: $(OBJS)
	$(CC) -o redscape $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

cards.o:
	$(CC) $(CFLAGS) -c src/cards.cpp

cutscenes.o:
	$(CC) $(CFLAGS) -c src/cutscenes.cpp

clean:
	rm -f *.o redscape
