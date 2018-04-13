#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "matriz_adj.h"


int main(int argc, char const *argv[])
{
	GRAFO g;
	int arestas, vertices;
	int origem, destino;
	scanf("%d %d", &vertices,&arestas);
	cria_grafo(&g, vertices);
	for(int i=0; i<arestas; i++){
		scanf("%d %d", &origem, &destino);
		inserir_aresta(&g, origem, destino, 0, 0);
	}
	while(scanf("%d", &origem) != EOF){
		scanf("%d", &destino);
		BUSCA d = bfs(&g, origem);
		imprime_caminho(d, origem, destino);
		printf("\n");
	}

	//desalocando espaco de memoria
	for(int i=0; i<g.n; i++){
		free(g.mat[i]);
	}
	free(g.mat);
	return 0;
}