#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct 
{
	int n;
	int **mat;
}GRAFO;

void cria_grafo(GRAFO *g, int n);
void inserir_aresta(GRAFO *g, int v1, int v2, int peso, int flag);
int verificar_aresta(GRAFO *g, int v1, int v2);
int * vertices_ajd(GRAFO *g, int v);
void matriz_transposta(GRAFO *g);
void imprimir_grafo(GRAFO *g);
void remover_aresta(GRAFO *g, int v1, int v2, int flag);
void aresta_menor_peso(GRAFO *g);

#endif