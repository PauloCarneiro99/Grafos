all: fila.o main.o busca.o matriz_adj.o
	gcc -o dfs fila.o busca.o main.o matriz_adj.o -Wall -std=c99
run: dfs
	./dfs
main.o: main.c busca.h matriz_adj.h
	gcc -c main.c -Wall -std=c99
busca.o: busca.c matriz_adj.h fila.h busca.h
	gcc -c busca.c -Wall -std=c99
fila.o: fila.c fila.h
	gcc -c fila.c -Wall -std=c99
matriz_adj.o: matriz_adj.c matriz_adj.h
	gcc -c matriz_adj.c -Wall -std=c99
clear:
	rm *.o dfs
zip:
	zip busca.zip fila.h fila.c busca.c busca.h matriz_adj.c matriz_adj.h main.c Makefile