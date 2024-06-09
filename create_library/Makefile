CC=clang
CFLAGS=-Wall -g
BINS=librarytest libhash.o libhash.so runtime_librarytest

all: $(BINS)

libhash.o: libhash.c libhash.h 
	$(CC) $(CFLAGS) -c libhash.c

libhash.so: libhash.c libhash.h 
	$(CC) $(CFLAGS) -fPIC -shared -o $@ libhash.c -lc

librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^

runtime_librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lhash

clean:
	rm $(BINS)