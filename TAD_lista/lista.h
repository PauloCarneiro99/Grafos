#ifndef LISTA_H
#define LISTA_H

typedef int elem;

typedef struct no
{
	struct no *prox, *ant;
	elem chave;
	int peso;
}NO;

typedef struct 
{
	NO *ini, *fim;
	int tam;	
}lista;

typedef struct 
{
	int n;
	lista *vet_lista;
}GRAFO_L;

void cria_lista(lista *l);
void insere_lista(lista *l, elem chave);
void remove_lista_fim(lista *l);
void remove_lista(lista *l, elem chave);
int lista_vazia(lista l);
NO* busca(lista l, elem chave);
void print_lista(lista l);
void insere_ordenado(lista *l, elem chave, int peso);
void cria_grafo_l(GRAFO_L *g, int v);
void inserir_aresta_l(GRAFO_L *g, int v1, int v2, int peso, int flag);
int verificar_aresta_l(GRAFO_L *g, int v1, int v2);
void vertices_adj_l(GRAFO_L *g, int v);
void imprimir_grafo_l(GRAFO_L *g);
void remover_aresta_l(GRAFO_L *g, int v1, int v2, int flag);
void aresta_menor_peso_l(GRAFO_L *g, int flag);
void grafo_transposto_l(GRAFO_L *g, int flag);

#endif