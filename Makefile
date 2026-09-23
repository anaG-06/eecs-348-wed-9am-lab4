CC = gcc
CFlags = -Wall -Wextra -Wpedantic -Werror

all: program

program: task1.c task2.c
	$(CC) $(CFlags) task1.c -o task1
	$(CC) $(CFlags) task2.c -o task2

clean:
	rm -f task1 task2 program