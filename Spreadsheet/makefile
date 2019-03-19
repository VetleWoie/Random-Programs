CC=gcc
CFLAGS=-I.

DEPS = spreadsheet.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

spreadsheet: spreadsheet.o
	$(CC) -o spreadsheet spreadsheet.o