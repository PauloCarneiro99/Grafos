#include <stdio.h>
#include <stdlib.h>
#include "matriz_adj.h"
#include "prim.h"

int main(int argc, char const *argv[])
{
	GRAFO g;
	int arestas, vertices;
	int origem, destino, peso;
	scanf("%d %d", &vertices,&arestas);
	cria_grafo(&g, vertices);
	for(int i=0; i<arestas; i++){ //lendo todas as arestas
		scanf("%d %d %d", &origem, &destino, &peso);
		inserir_aresta(&g, origem, destino, peso, 1); //inserindo um grafo com flag 1, isto eh nao digrafo
	}
	primMST(&g);

	//desalocando espaco de memoria
	for(int i=0; i<g.n; i++){
		free(g.mat[i]);
	}
	free(g.mat);
	return 0;
}