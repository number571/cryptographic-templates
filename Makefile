CC=gcc
LN=ld
CFLAGS=-Wall -std=c99

SOURCES=cryptolib/encoding/alpha.c cryptolib/classic/caesar.c cryptolib/classic/vigenere.c cryptolib/classic/simple_substitution.c
HEADERS=cryptolib/encoding/alpha.h cryptolib/classic/caesar.h cryptolib/classic/vigenere.h cryptolib/classic/simple_substitution.h
OBJECTS=cryptolib/encoding/alpha.o cryptolib/classic/caesar.o cryptolib/classic/vigenere.o cryptolib/classic/simple_substitution.o

.PHONY: default compile link run clean 
default: compile link run clean
compile: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)
link: $(OBJECTS)
	$(LN) -r $(OBJECTS) -o cryptolib.o
run:  
	$(CC) main.c cryptolib.o && ./a.out
clean:
	rm -f a.out *.o cryptolib/classic/*.o cryptolib/encoding/*.o
