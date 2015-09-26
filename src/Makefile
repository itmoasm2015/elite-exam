CFLAGS=-std=c99 -g -O0

all: crackme
	cp crackme repo/crackme

crackme: main.o check.o
	$(CC) $(CFLAGS) -o $@ $^

%.easy: %.o main.o
	$(CC) $(CFLAGS) -o $@ $^

%.hard: %.o main.o
	$(CC) $(CFLAGS) -o $@ $^

gen%: %-gen.o gen.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $^

%-gen.o: %-gen.c
	$(CC) $(CFLAGS) -c -o $@ $^

%.o: %.c
	$(CC) -std=c99 -Os -c -o $@ $^

%.o: %.asm
	yasm -felf64 -o $@ $^

2.o: 2.c
	$(CC) -std=c99 -mfpmath=387 -Os -c -o $@ $^
