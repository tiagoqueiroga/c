CC=cc
CFLAGS=-Wall
BINS=a.out

all: $(BINS)

a.out: game.c
	$(CC) $(CFLAGS) game.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o build/game

clean:
	rm $(BINS)