CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: s21_cat clean

s21_cat: cat_main.o main.o
	$(CC) $(CFLAGS) cat_main.o main.o -o s21_cat

cat_main.o:
	$(CC) $(CFLAGS) -c cat_main.c

main.o:
	$(CC) $(CFLAGS) -c main.c

test:
	sh cat_test.sh

clean:
	rm -rf *.o *.out

