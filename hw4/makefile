all: trap_openmp trap_serial

trap_openmp:trap_openmp.c
	gcc -g -fopenmp trap_openmp.c -o trap_openmp
trap_serial:trap_serial.c
	gcc -g -fopenmp trap_serial.c -o trap_serial
clean:
	rm -f trap_openmp trap_serial
