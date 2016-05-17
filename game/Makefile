OBJ := main.o array.o func.o screen.o color.o terminfo.o stdin.o move.o game.o
CC := gcc -g
CFLAGS := -Wall -O2

compile: $(OBJ)
	$(CC) $(OBJ) -o game

clean:
	rm $(OBJ)
