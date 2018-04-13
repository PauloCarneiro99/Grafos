#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "busca.h"


//**************BUSCA EM LARGURA**************

//	funcao malloca os vetores de predecessor, cor e distancia e seta valores iniciais
void cria_bfs(BUSCA *b, int n){
	cria_fila(&b->f);
	b->cor = malloc(sizeof(short)*n);
	b->prd = malloc(sizeof(short)*n);
	b->dist = malloc(sizeof(int)*n);
	b->t = NULL;
	for(int i=0; i<n; i++){
		b->cor[i] = branco;
		b->prd[i] = -1;
		b->dist[i] = 0;
	}
}

//Funcao que acha todos os caminhos possiveis e os armazena no vetor de precedencia da BFS, retornando a propria BFS
BUSCA bfs(GRAFO *g, int origem){
	BUSCA b;
	cria_bfs(&b, g->n);
	b.cor[origem] = cinza;
	b.dist[origem] = 0;
	push_fila(&b.f, origem);
	while(!fila_vazia(b.f)){
		int aux = front(b.f);
		int *v_adj = vertices_ajd(g, aux);
		for(int i=1; i<v_adj[0]; i++){ //comeca em 1 pois, a posicao 0 corresponde ao tamanho do vetor
			if(b.cor[v_adj[i]] == branco){
				b.cor[v_adj[i]] = cinza;
				b.dist[v_adj[i]] = b.dist[aux] +1;
				b.prd[v_adj[i]] = aux;
				push_fila(&b.f, v_adj[i]);
			}
		}
		dequeue(&b.f);
		b.cor[aux] = preto;
	}
	return b;
}

//**************BUSCA EM PROFUNDIDADE**************

//	funcao malloca os vetores de predecessor, cor e distancia e seta valores iniciais
void cria_dfs(BUSCA *d, int n){
	d->cor = malloc(sizeof(short)*n);
	d->prd = malloc(sizeof(short)*n);
	d->t = malloc(sizeof(timestamps)*n);
	d->dist = NULL;
	for(int i=0; i<n; i++){
		d->cor[i] = branco;
		d->prd[i] = -1;
		d->t[i].inicio = d->t[i].conclusao = 0;
	}
}

void dfs_visit(BUSCA d, GRAFO *g, int i, int *time){
	d.cor[i] = cinza;
	d.t[i].inicio = (*time);
	(*time)++;
	int *v = vertices_ajd(g, i);
	for(int j=1; j<v[0]; j++){ //percorrendo todos os adjacentes
		if(d.cor[v[j]] == branco){//quando for branco, chama recurisvamente para fazer a busca em profundidade
			d.prd[v[j]] = i;
			dfs_visit(d, g, v[j], time);
		}
	}
	d.cor[i] = preto;
	d.t[i].conclusao = (*time);
	(*time)++;
}


BUSCA dfs(GRAFO *g, int origem){
	BUSCA d;
	int time = 1;
	cria_dfs(&d, g->n);
	for(int i=origem; i<g->n; i++){ //passando em todos os vertices do grafo, começando a partir da origem
		if(d.cor[i] == branco){
			dfs_visit(d,g, i, &time);
		}
	}
	return d;
}



//o vetor de precedencia da bfs possui o caminho partindo de um destino ate uma origem setada.
//porem esse caminho esta ao contrario, logo a recursao vai ate o inicio e volta imprimindo
//funciona na impressao tanto do caminho da dfs qnt pro caminho da bfs
void imprime_caminho(BUSCA b, int origem, int atual){
	if(b.prd[atual] == -1 && atual != origem){
		return;
	}
	if(atual != origem)
		imprime_caminho(b, origem, b.prd[atual]);
	printf("%d ", atual);
}