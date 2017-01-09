TARGET=timecl

${TARGET}:daytimetcpcli.o pubfunc.o
	gcc $^ -o $@ -g -Wall -O2
	rm -rf *.o
%.o:%.c
	gcc -c $^ -o $@ -g -Wall -O2

clean:
	rm -f *.o
	rm -f ${TARGET}
