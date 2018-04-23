#ifndef FILA_H
#define FILA_H

typedef int elem;

typedef struct no
{
	struct no *prox, *ant;
	elem chave;	
}NO;

typedef struct 
{
	NO *ini;
	NO *fim;
}fila;

void push_fila(fila *f, elem chave);
void dequeue(fila *f);
void cria_fila(fila *f);
int front(fila f);
int fila_vazia(fila f);


#endif