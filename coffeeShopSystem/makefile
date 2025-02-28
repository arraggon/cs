CC=g++
EXE_FILE=shop_run

all: $(EXE_FILE)

$(EXE_FILE): coffee.o menu.o order.o display.o shop.o prog.cpp
	$(CC) coffee.o menu.o order.o display.o shop.o prog.cpp -o $(EXE_FILE)

menu.o: menu.h menu.cpp
	$(CC) -c menu.cpp

coffee.o: coffee.h coffee.cpp
	$(CC) -c coffee.cpp

shop.o: shop.h shop.cpp
	$(CC) -c shop.cpp

order.o: order.h order.cpp
	$(CC) -c order.cpp

display.o: display.h display.cpp
	$(CC) -c display.cpp

clean:
	rm -f *.o $(EXE_FILE)