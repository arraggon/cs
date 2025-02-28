# Define the C++ compiler
CC=g++

# Define the name of the executable file
EXE_FILE=catalog_run

# Default target to build the new program
all: $(EXE_FILE)

# Target to build the new program
$(EXE_FILE): catalog.o catalog.h run_catalog.cpp game.o
	$(CC) catalog.o run_catalog.cpp game.o -o $(EXE_FILE)

# Rule for building the catalog.o target (for the new program)
catalog.o: catalog.h catalog.cpp
	$(CC) -c catalog.cpp

# Rule for building the game.o target (for the included feature)
game.o: game.h game.cpp
	$(CC) -c game.cpp

# Target for cleaning up object files and the executable
clean:
	rm -f *.o $(EXE_FILE)
