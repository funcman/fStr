CFLAGS?=-O2 -Wall

all: libfstr.a

libfstr.a: fstr.o
	$(AR) -r libfstr.a fstr.o

fstr.o: fstr.c fstr.h
	$(CC) $(CFLAGS) -c fstr.c

clean:
	$(RM) fstr.o libfstr.a

install: all
	cp fstr.h /usr/include
	cp libfstr.a /usr/lib

uninstall:
	$(RM) /usr/include/fstr.h
	$(RM) /usr/lib/libfstr.a
