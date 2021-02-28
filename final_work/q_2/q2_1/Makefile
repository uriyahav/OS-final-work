CC=gcc
FLAG=-Wall

all: check_pid

check_pid: check_pid.c
	$(CC) $(FLAG) check_pid.c -g -o run
check_pid.c:
	$(CC) $(FLAG) -g -c check_pid.c
.PHONY: clean
clean:
	rm -f *.o 
