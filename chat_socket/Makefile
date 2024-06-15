CFLAGS=-Wall -Wextra -std=c11 -pedantic 

all: server client

server: server.c
	$(CC) $(CFLAGS) -o build/server server.c

client: client.c
	$(CC) $(CFLAGS) -o build/client client.c

clean:
	rm -f build/*