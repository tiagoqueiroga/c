CC=cc
CFLAGS=-Wall
BINS=a.out

#cc game.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11;

all: $(BINS)

a.out: game.c
	$(CC) $(CFLAGS) game.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	rm $(BINS)