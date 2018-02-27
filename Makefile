# Makefile for payroll project

CC=g++
CFLAGS=-I.
DEPS = 	masterData.hh \
	menu.hh \
	record.hh

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pay: record.o masterData.o readFile.o menu.o 
	$(CC) -o pay_prg record.o masterData.o readFile.o menu.o $(CFLAGS)

clean:
	rm record.o masterData.o readFile.o menu.o
