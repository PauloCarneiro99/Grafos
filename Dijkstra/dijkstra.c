#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade.h"
#include "matriz_adj.h"
#include <limits.h>
#include "dijkstra.h"

void imprime_caminho(dijk b, int origem, int atual){
	if(b.parent[atual] == -1 && atual != origem){
		return;
	}
	if(atual != origem)
		imprime_caminho(b, origem, b.parent[atual]);
	printf("%d ", atual);
}


//funcao que inicializa o vetor de dist com infinito e o vetor de parent como -1
void inicia(int vertice, dijk *d){
	d->dist = malloc(sizeof(int)*vertice);
	d->parent = malloc(sizeof(int)*vertice);
	for(int i=0; i<vertice; i++){
		d->dist[i] = INT_MAX;
		d->parent[i] = -1;
	}
}

void libera_memoria(dijk *d){
	free(d->dist);
	free(d->parent);
}


//acha o caminho minimo
void dijkstra(GRAFO *g, int origem, int destino){
	dijk d;
	inicia(g->n, &d);
	fila f;
	cria_fila(&f);
	d.dist[origem] = 0;
	insere(&f,origem,0); //insere o primeiro no
	while(!empty(&f)){
		NO* no = front(&f);
		int v1 = no->v1;
		int peso = no->peso;
		pop(&f);
		if(peso > d.dist[v1]) continue; //vai para a proxima interacao do loop
		int *v_adj = vertices_ajd(g,v1);
		for(int j=1 ; j< v_adj[0]; j++){
			if(d.dist[v1] + g->mat[v1][v_adj[j]] < d.dist[v_adj[j]]){
				//altera o vetor de dist e o de parent
				d.parent[v_adj[j]] = v1;
				d.dist[v_adj[j]] = d.dist[v1] + g->mat[v1][v_adj[j]];
				insere(&f, v_adj[j], d.dist[v1] + g->mat[v1][v_adj[j]]);
			}	
		}
	}
	imprime_caminho(d,origem,destino);
	printf("\n");
	libera_memoria(&d);
}



