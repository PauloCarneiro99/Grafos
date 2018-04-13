#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*
	Esse .c corresponde a implementação de todas as operações basicas de fila que serao utilizadas 
	na busca em largura. O push como de costume insere no final da fila e o dequeue retira o nó no
	inicio da fila. Por isso o struct fila possui um ponteiro para o inicio e para o final da fila, 
	facilitando nas operacoes basicas. 
*/


void push_fila(fila *f, elem chave){
	NO *temp = (NO*)malloc(sizeof(NO));
	temp->chave = chave;
	temp->prox = NULL;
	temp->ant = f->fim;
	if(f->ini == NULL)
		f->ini = temp;
	if(f->fim != NULL)
		f->fim->prox = temp;
	f->fim = temp;
}

void dequeue(fila *f){
	NO *temp = f->ini;
	if(f->ini != NULL){//removendo elemento de uma fila vazia
		f->ini = temp->prox;
		free(temp);
	}
	if(f->ini != NULL)
		f->ini->ant = NULL;
	else{ //a fila esta vazia
		f->fim = NULL;
	}
}

//retorna o elemento que esta no inicio da fila, isto eh, o proximo no a ser removido
int front(fila f){
	return f.ini->chave;
}

//setando os ponteiro da fila como null
void cria_fila(fila *f){
	f->ini = NULL;
	f->fim = NULL;
}

//retorna 1 se a fila estiver vazia e zero caso o contrario
int fila_vazia(fila f){
	if(f.ini == NULL)
		return 1;
	return 0;
}