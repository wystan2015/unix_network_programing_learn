BASEDIR=${HOME}
ALLDIRS=${BASEDIR}/unix_network_programing_learn/src/chp1/timecltip6 \
		${BASEDIR}/unix_network_programing_learn/src/chp1/timeclt \
		${BASEDIR}/unix_network_programing_learn/src/chp1/timesvr

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
	
