CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -O2 -lm --static -std=c99
objects = Main.o
Main : $(objects)
	$(CC) -o Main $(objects) $(LDFLAGS)
Main.o : Main.c
	$(CC) -c Main.c $(CFLAGS)
.PHONY : clean
clean :
	-rm Main $(objects)

