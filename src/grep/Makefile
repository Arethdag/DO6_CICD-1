CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: s21_grep clean

s21_grep: grep_main.o main.o
	$(CC) $(CFLAGS) grep_main.o main.o -o s21_grep

grep_main.o:
	$(CC) $(CFLAGS) -c grep_main.c

main.o:
	$(CC) $(CFLAGS) -c main.c

test:
	sh grep_test.sh

clean:
	rm -rf *.o *.out
