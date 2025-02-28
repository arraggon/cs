CC=g++ -std=c++11 -g
exe = huntw

all: $(exe)

$(exe): bats.o event.o game.o gold.o room.o stalactites.o wumpus.o start.o armor.o ladup.o laddown.o tp.o main.o
	$(CC) bats.o event.o game.o gold.o room.o stalactites.o wumpus.o start.o armor.o ladup.o laddown.o tp.o main.o -o $(exe)

main.o: main.cpp
	$(CC) -c main.cpp

bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp

event.o: event.h event.cpp
	$(CC) -c event.cpp

game.o: game.h game.cpp
	$(CC) -c game.cpp

gold.o: gold.h gold.cpp
	$(CC) -c gold.cpp

room.o: room.h room.cpp
	$(CC) -c room.cpp

stalactites.o: stalactites.h stalactites.cpp
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(CC) -c wumpus.cpp

start.o: start.h start.cpp
	$(CC) -c start.cpp

armor.o : armor.h armor.cpp
	$(CC) -c armor.cpp

ladup.o : ladup.h ladup.cpp
	$(CC) -c ladup.cpp

laddown.o : laddown.h laddown.cpp
	$(CC) -c laddown.cpp

tp.o : tp.h tp.cpp
	$(CC) -c tp.cpp

clean:
	rm -f *.o $(exe)
