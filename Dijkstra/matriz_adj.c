#include <stdio.h>
#include <stdlib.h>
#include "matriz_adj.h"

//malloca o espaco para a matriz e a inicializa com -1 para evitar lixo de memoria
void cria_grafo(GRAFO *g, int n){
	g->n = n;
	g->mat = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++){
		g->mat[i] = (int*)malloc(sizeof(int)*n);
	}

	for(int i=0; i<g->n; i++)
		for(int j=0; j<g->n; j++)
			g->mat[i][j] = -1;
}

//se a flag for 1 o grafo nao eh orientado logo, a matriz deve ser espelhada
void inserir_aresta(GRAFO *g, int v1, int v2, int peso, int flag){
	if(flag == 1){
		g->mat[v1][v2] = peso;
		g->mat[v2][v1] = peso;
	}else
		g->mat[v1][v2] = peso;
}

//retorna 1 se a aresta em questao existir
int verificar_aresta(GRAFO *g, int v1, int v2){
	if(g->mat[v1][v2] == -1)
		return -1;
	return 1;
}

//retorna vetor com os vertices adjacentes ao vertice desejado
int * vertices_ajd(GRAFO *g, int vertice){
	int *v = malloc(sizeof(int));
	v[0] = 1; //em v[0] quardo o tamanho do vetor de retorno
	for(int i=0; i<g->n; i++)
		if(g->mat[vertice][i] != -1){
			v[0]++;
			v = realloc(v,sizeof(int)*v[0]);
			v[v[0]-1] = i;
		}
	return v;
}

void matriz_transposta(GRAFO *g){
	for(int i=0;i<g->n; i++){
		for(int j=0; j<g->n; j++){
			if(g->mat[j][i] != -1)
				printf("%d ",g->mat[j][i]);
			else
				printf(". ");
		}
		printf("\n");
	}
}

void imprimir_grafo(GRAFO *g){
	for(int i=0; i<g->n; i++){
		for(int j=0; j<g->n; j++){
			if(g->mat[i][j] == -1)
				printf(". ");
			else
				printf("%d ", g->mat[i][j]);
		}
		printf("\n");
	}
}

//se a flag for 1 o grafo nao eh orientado logo, a matriz deve ser espelhada
void remover_aresta(GRAFO *g, int v1, int v2, int flag){
	if(flag == 1){
		g->mat[v1][v2] = -1;
		g->mat[v2][v1] = -1;
	}else{
		g->mat[v1][v2] = -1;
	}
}

void aresta_menor_peso(GRAFO *g){
	int peso = -1;
	int v1, v2;
	v1 = v2 = 0;
	for(int i=0; i<g->n;i++){
		for(int j=0; j<g->n; j++){
			if(g->mat[i][j] != -1)
				if(peso == -1 || g->mat[i][j] < peso){
					peso = g->mat[i][j];
					v1 = i;
					v2 = j;
				}
		}
	}
	if(v1 < v2)
		printf("%d %d\n",v1, v2);
	else
		printf("%d %d\n",v2, v1);
}