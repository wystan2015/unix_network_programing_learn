CC=gcc
CFLAG=-Wall -O2 -g
EXOBJ=${HOME}/bin/timecltip6
IPUB=-I${HOME}/unix_network_programing_learn/include
LINKRULE=-L ${HOME}/lib -lpub
TARGETS=${EXOBJ}
all:${TARGETS}
clean:
	@- rm -rf ${EXOBJ}
	@- rm -rf *.o
${EXOBJ}:timecltip6.o
	${CC} ${IPUB} -o $@ $< ${CFLAG} ${LINKRULE} 
%.o:%.c
	${CC} ${IPUB} -o $@  -c $< ${CFLAG} ${LINKRULE} 








