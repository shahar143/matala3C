.PHONY: clean
COMPILER = gcc
FLAGS = -Wall -g

isort: isort.o isort.h
	$(COMPILER) $(FLAGS) isort.o -o isort

txtfind: txtfind.o txtfind.h
	$(COMPILER) $(FLAGS) txtfind.o -o txtfind

isort.o: isort.c isort.h
	$(COMPILER) -c $(FLAGS) isort.c

txtfind.o: txtfind.c txtfind.h
	$(COMPILER) -c $(FLAGS) txtfind.c

clean:
	rm -f *.o txtfind isort