CC=gcc
CFLAG=-Wall -O2 -g
EXLIB=../../lib/libpub.a
PUBOBJS=pub.o
TARGETS=${EXLIB}

all:${TARGETS}

clean:
	@- rm -rf ${EXLIB}
	@- rm -rf *.o
${TARGETS}:${PUBOBJS}
	ar -rv $@ $?
