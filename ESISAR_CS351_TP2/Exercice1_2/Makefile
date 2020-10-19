

all : out/obj/main.o
	@mkdir -p out 
	@mkdir -p out/obj
	gcc -ansi -pedantic -std=c99 -Wall -o out/exe out/obj/main.o


out/obj/main.o : src/main.c includes/main.h
	@mkdir -p out 
	@mkdir -p out/obj
	gcc -o $@  -c src/main.c -ansi -pedantic -std=c99 -Wall -Iincludes


.PHONY :mrproper miseaupoint all
miseaupoint : out/obj/main.o src/main.c includes/main.h
	
	@mkdir -p out 
	@mkdir -p out/obj
	gcc -DMISEAUPOINT -o out/obj/main.o  -c src/main.c -ansi -pedantic -std=c99 -Wall -Iincludes
	gcc -DMISEAUPOINT -ansi -pedantic -std=c99 -Wall -o out/exe out/obj/main.o

mrproper: 
	rm -r out

