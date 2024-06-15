CC=clang
CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb

malloc: queue.c
	$(CC) queue.c -o build/queue $(CFLAGS)

clean:
	rm build/queue