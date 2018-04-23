#ifndef LISTA_H
#define LISTA_H

typedef int elem;

typedef struct no_l
{
	struct no_l *prox, *ant;
	elem chave;
	int peso;
}NO_l;

typedef struct 
{
	NO_l *ini, *fim;
	int tam;	
}lista;

void libera_memoria_lista(lista *l);
void cria_lista(lista *l);
void insere_lista(lista *l, elem chave, int peso);
void remove_lista_fim(lista *l);
int lista_vazia(lista l);
void print_lista(lista l);

#endif