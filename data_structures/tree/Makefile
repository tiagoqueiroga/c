CC=clang
CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb

malloc: tree.c
	$(CC) tree.c -o build/tree $(CFLAGS)

clean:
	rm build/tree