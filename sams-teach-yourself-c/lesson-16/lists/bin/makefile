CC = gcc
CFLAGS = -Wall -ansi -std=c11 -g
SRCDIR = ../src
BINDIR = .
TESTDIR = ../tests

all: $(BINDIR)/sll $(BINDIR)/dll $(BINDIR)/stack

sll: $(SRCDIR)/sll.c $(SRCDIR)/result.c
	$(CC) $(CFLAGS) -o $(BINDIR)/test-sll $(TESTDIR)/test-sll.c $(SRCDIR)/sll.c $(SRCDIR)/result.c

dll: $(SRCDIR)/dll.c $(SRCDIR)/result.c
	$(CC) $(CFLAGS) -o $(BINDIR)/test-dll $(TESTDIR)/test-dll.c $(SRCDIR)/dll.c $(SRCDIR)/result.c

stack: $(SRCDIR)/stack.c $(SRCDIR)/result.c
	$(CC) $(CFLAGS) -o $(BINDIR)/test-stack $(TESTDIR)/test-stack.c $(SRCDIR)/stack.c $(SRCDIR)/result.c $(SRCDIR)/dll.c

clean:
	rm -f $(BINDIR)/test-sll $(BINDIR)/test-dll $(BINDIR)/test-stack
