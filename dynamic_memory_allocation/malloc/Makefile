CC=clang
CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb

malloc: malloc.c
	$(CC) malloc.c -o build/malloc $(CFLAGS)

clean:
	rm build/malloc