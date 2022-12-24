# Directories
SFML = C:\Users\renyj\Documents\Molecule\C++\SFML
EXEPTH = execute/main.exe
CLASS = src/Square.cpp

# Compiler and flags
CC = g++
CFLAGS = -g -Wall
LINKS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Executable
all: compile link

link: main.o Paddle.o Square.o
	$(CC) main.o -o $(EXEPTH) -L$(SFML)\lib $(LINKS)
compile: src/*.cpp
	$(CC) $(CFLAGS) -c $? -I$(SFML)\include
clean:
	rm *.o $(EXEPTH)