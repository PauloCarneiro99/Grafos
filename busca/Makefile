all: fila.o main.o busca.o matriz_adj.o lista.o
	gcc -o busca fila.o busca.o main.o matriz_adj.o  lista.o -Wall -std=c99
run: busca
	./busca
main.o: main.c busca.h matriz_adj.h lista.h
	gcc -c main.c -Wall -std=c99
busca.o: busca.c matriz_adj.h fila.h busca.h lista.h
	gcc -c busca.c -Wall -std=c99
fila.o: fila.c fila.h
	gcc -c fila.c -Wall -std=c99
lista.o: lista.c lista.h
	gcc -c lista.c -Wall -std=c99
matriz_adj.o: matriz_adj.c matriz_adj.h
	gcc -c matriz_adj.c -Wall -std=c99
clear:
	rm *.o busca
zip:
	zip Busca.zip fila.h fila.c busca.c busca.h matriz_adj.c matriz_adj.h main.c lista.c lista.h Makefile
