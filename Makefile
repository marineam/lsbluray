LIBS=$(shell pkg-config --libs libbluray)
CFLAGS=-Wall

all: lsbluray

lsbluray: lsbluray.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
