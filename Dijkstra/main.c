#include <stdio.h>
#include <stdlib.h>
#include "matriz_adj.h"
#include "dijkstra.h"

int main(int argc, char const *argv[])
{
	GRAFO g;
	int arestas, vertices, peso;
	int origem, destino;
	scanf("%d %d", &vertices,&arestas);
	cria_grafo(&g, vertices);
	for(int i=0; i<arestas; i++){
		scanf("%d %d %d", &origem, &destino, &peso);
		inserir_aresta(&g, origem, destino, peso, 0);
	}

	while(scanf("%d %d", &origem, &destino) != EOF){
		dijkstra(&g,origem,destino);
	}

	//desalocando espaco de memoria
	for(int i=0; i<g.n; i++){
		free(g.mat[i]);
	}
	free(g.mat);
	return 0;
}
