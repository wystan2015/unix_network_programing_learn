CC=gcc
CFLAG=-Wall -O2 -g
EXOBJ=${HOME}/unix_network/bin/timesvr
IPUB=-I${HOME}/unix_network/include
LINKRULE=-L ${HOME}/unix_network/lib -lpub
TARGETS=${EXOBJ}
all:${TARGETS}
clean:
	@- rm -rf ${EXOBJ}
	@- rm -rf *.o
${EXOBJ}:timesvr.o
	${CC} ${IPUB} -o $@ $< ${CFLAG} ${LINKRULE} 
%.o:%.c
	${CC} ${IPUB} -o $@  -c $< ${CFLAG} ${LINKRULE} 








