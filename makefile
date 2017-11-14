sep_str: sepstr.o
	gcc -o sep_str sepstr.o

sepstr.o: sepstr.c
	gcc -c sepstr.c

run:
	./sep_str
