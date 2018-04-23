#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//inicializa os ponteiros da lista como null, e o tamanho com 0
void cria_lista(lista *l){
	l->ini = NULL;
	l->fim = NULL;
	l->tam = 0;
}

int lista_vazia(lista l){
	if(l.fim == NULL)
		return 1;
	return 0;
}

void insere_lista(lista *l, elem chave, int peso){ //inserindo no final da lista
	NO_l* temp = malloc(sizeof(NO_l));
	temp->ant = l->fim;
	temp->peso = peso;
	temp->chave = chave;
	temp->prox = NULL;
	if(l->fim != NULL)
		l->fim->prox = temp;
	if(l->ini == NULL)
		l->ini = temp;
	l->fim = temp;
}


void remove_lista_fim(lista *l){ //removendo do final da lista
	if(l->fim == NULL)
		printf("lista ja estava vazia\n");
	else{
		l->tam -= 1;
		if(l->fim == l->ini){
			free(l->fim);
			l->fim = NULL;
			l->ini = NULL;
		}else{
			NO_l*temp = l->fim->ant;
			free(l->fim);
			l->fim = temp;
			l->fim->prox = NULL;
		}
	}
}

void libera_memoria_lista(lista *l){
	NO_l*p = l->fim;
	NO_l *aux;
	while(p != NULL){
		aux = p->ant;
		free(p);
		p = aux;
	}
}

void print_lista(lista l){
	NO_l*p = l.fim;
	while(p != NULL){
		printf("%d ",p->chave);
		p = p->ant;
	}
}
