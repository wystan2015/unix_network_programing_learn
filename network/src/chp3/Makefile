BASEDIR=${HOME}
ALLDIRS=${BASEDIR}/unix_network_programing_learn/src/chp3/c_sort \

all:
	@for subdir in ${ALLDIRS}; \
	do \
		cd $$subdir; \
		make clean; \
		make; \
		echo "Done"; \
	done
clean:
	 @for subdir in ${ALLDIRS}; \
    do \
        cd $$subdir; \
        make clean; \
        echo "Done"; \
    done
	
