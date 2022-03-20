CC = gcc-11
CFLAGS = -O3 -Wall

SRC = 895-run

TARGET = a.out

.PHONY: run clean

all: ${TARGET}

${TARGET}: ${SRC}.c
	${CC} ${CFLAGS} ${SRC}.c -o ${TARGET}

run: ${TARGET}
	./${TARGET}

clean:
	rm -rf ./*.o ./${TARGET}

