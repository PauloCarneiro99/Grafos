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

void insere_lista(lista *l, elem chave){ //inserindo no final
	l->tam += 1;
	NO* temp = malloc(sizeof(NO));
	temp->chave = chave;
	temp->prox = NULL;
	temp->ant = l->fim;
	if(l->fim != NULL)
		l->fim->prox = temp;
	l->fim = temp;
	if(l->ini == NULL)
		l->ini = temp;
}

NO* busca(const lista l, elem chave){
	NO* p = l.ini;
	while(p != NULL){
		if(p->chave == chave)
			break;
		p = p->prox;
	}
	return p;
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
			NO*temp = l->fim->ant;
			free(l->fim);
			l->fim = temp;
			l->fim->prox = NULL;
		}
	}
}

void remove_lista(lista *l, elem chave){
	NO* temp = busca(*l, chave);
	if(temp == NULL)
		return; //tentando remover algo que nao esta inserido na lista
	l->tam -= 1;
	if(temp == l->ini){
		if(temp->prox != NULL){
			temp->prox->ant = NULL;
			l->ini = temp->prox;
			free(temp);
		}else{
			l->ini = NULL;
			l->fim = NULL;
			free(temp);
		}
	}
	else if(temp == l->fim){
		if(temp->ant != NULL){
			temp->ant->prox = NULL;
			l->fim = temp->ant;
			free(temp);
		}else{
			l->ini = NULL;
			l->fim = NULL;
			free(temp);
		}
	}else{
		if(temp->ant != NULL)
			temp->ant->prox = temp->prox;
		if(temp->prox !=NULL)
			temp->prox->ant = temp->ant;
		free(temp);
	}
}

//mantem a lista de elementos ordenada, inserindo o novo NO ja na sua posicao correta
void insere_ordenado(lista *l, elem chave, int peso){
	NO*temp = malloc(sizeof(NO));
	temp->chave = chave;
	temp->peso = peso;
	if(!lista_vazia(*l)){
		if(chave == l->ini->chave){ //evitando inserir elemento repetido
			l->ini->peso = peso;
			return;
		}
		if(chave < l->ini->chave){
			l->ini->ant = temp;
			temp->ant = NULL;
			temp->prox = l->ini;
			l->ini = temp;
		}	
		else{
			NO* aux = l->ini;
			while(aux->prox != NULL && aux->prox->chave < chave){
				aux = aux->prox;
			}
			if(aux->prox != NULL)
				if(aux->prox->chave == chave){ //tentando inserir uma chave igual, somente altero os pesos
					aux->prox->peso = peso;
					return ;
				}
			if(aux->prox == NULL){
				temp->prox = NULL;	
				l->fim = temp;
			}else{
				temp->prox = aux->prox;
				aux->prox->ant = temp;	
			}
			aux->prox = temp;
			temp->ant = aux;
		}
	}else{ //inserindo o primeiro elemento
		l->ini = l->fim = temp;
		temp->ant = NULL;
		temp->prox = NULL;
	}
}

void print_lista(lista l){
	NO*p = l.ini;
	while(p != NULL){
		printf("%d(%d) ",p->chave, p->peso);
		p = p->prox;
	}
}
//malloca o vetor de listas e depois percorre esse vetor inicializando as listas
void cria_grafo_l(GRAFO_L *g, int v){
	g->n = v;
	g->vet_lista = (lista*)malloc(sizeof(lista)*v);
	for(int i=0; i<v; i++)
		cria_lista(&g->vet_lista[i]);
}

void inserir_aresta_l(GRAFO_L *g, int v1, int v2, int peso, int flag){
	if(flag == 1){ //como o grafo nao eh digrafo, insiro duas vezes, pois a aresta corresponte tanto qnt a ida quanto a volta de um vertice a outro
		insere_ordenado(&g->vet_lista[v1], v2, peso);
		insere_ordenado(&g->vet_lista[v2], v1, peso);
	}else //grafo eh digrafo
		insere_ordenado(&g->vet_lista[v1], v2, peso);
}


//retorna 1 se a aresta(v1,v2) existir e -1 caso ela nao exista
int verificar_aresta_l(GRAFO_L *g, int v1, int v2){
	NO* aux = g->vet_lista[v1].ini;
	while(aux != NULL && aux->chave != v2)
		aux = aux->prox;
	if(aux == NULL)
		return -1;
	return 1;
}

//imprime os vertices adjacentes a um vertice 'v', percorrendo a lista de adjacencia ordenada correspondende a esse vertice
void vertices_adj_l(GRAFO_L *g, int v){
	NO* aux = g->vet_lista[v].ini;
	while(aux != NULL){
		printf("%d ",aux->chave);
		aux = aux->prox;
	}
	printf("\n");
}

void imprimir_grafo_l(GRAFO_L *g){
	for(int i=0; i<g->n; i++){
		printf("%d. ",i);
		print_lista(g->vet_lista[i]);
		printf("\n");
	}
}

void aresta_menor_peso_l(GRAFO_L *g, int flag){
	int k,m;
	int peso = -1;
	for(int i=0; i<g->n; i++){
		NO* aux = g->vet_lista[i].ini;
		while(aux != NULL){
			if(peso == -1 || aux->peso < peso){
				peso = aux->peso;
				k = i;
				m = aux->chave;
			}
			aux = aux->prox;	
		}
	}

	if(m < k && flag == 1)
		printf("%d %d\n",m, k);
	else
		printf("%d %d\n",k, m);	
}

void grafo_transposto_l(GRAFO_L *g, int flag){
	GRAFO_L aux;
	cria_grafo_l(&aux, g->n);
	for(int i=0; i<g->n; i++){
		NO *temp = g->vet_lista[i].ini;
		while(temp != NULL){
			inserir_aresta_l(&aux, temp->chave, i, temp->peso, flag);
			temp = temp->prox;
		}
	}
	imprimir_grafo_l(&aux);
	//liberando o espaco alocado
	for(int i=0; i<g->n; i++){
			NO*auxiliar = aux.vet_lista[i].ini;
			NO*temp = auxiliar->prox;
			while(auxiliar != NULL){
				free(auxiliar);
				auxiliar = temp;
				if(auxiliar != NULL)
					temp = auxiliar->prox;
			}
		}
}

void remover_aresta_l(GRAFO_L *g, int v1, int v2, int flag){
	if(flag == 1){
		remove_lista(&g->vet_lista[v1], v2);		
		remove_lista(&g->vet_lista[v2], v1);		
	}else
		remove_lista(&g->vet_lista[v1], v2);		
}