CC=gcc
FLAG=-Wall

all: client server

client: client.c
	$(CC) $(FLAG) client.c -g -o client
client.c:
	$(CC) $(FLAG) -g -c client.c
server: server.c
	$(CC) $(FLAG) server.c -g -o server
server.c:
	$(CC) $(FLAG) -g -c server.c
.PHONY: clean
clean:
	rm -f *.o 
