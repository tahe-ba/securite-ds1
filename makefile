CC = gcc
CFLAGS = -g
SOURCES = $(wildcard *.c)
BINAIRES = $(patsubst %.c,%.o,${SOURCES})

all : ${BINAIRES}
	${CC} ${CFLAGS} -o main $^

main.o : header.h

header.o : header.h

clean :
	rm -f *.o
	rm -f main