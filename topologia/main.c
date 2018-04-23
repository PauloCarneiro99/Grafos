#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "matriz_adj.h"
#include "lista.h"

int main(int argc, char const *argv[])
{
	GRAFO g;
	lista l;
	int arestas, vertices;
	int origem, destino;
	scanf("%d %d", &vertices,&arestas);

	cria_grafo(&g, vertices);
	cria_lista(&l);

	for(int i=0; i<arestas; i++){
		scanf("%d %d", &origem, &destino);
		inserir_aresta(&g, origem, destino, 0, 0);
	}

	dfs(&g, 0, &l);
	print_lista(l);

	//desalocando espaco de memoria
	libera_memoria_lista(&l);
	for(int i=0; i<g.n; i++){
		free(g.mat[i]);
	}
	free(g.mat);
	return 0;
}