#ifndef BUSCA_H
#define BUSCA_H

#include "fila.h"
#include "matriz_adj.h"
#include "lista.h"

enum{branco, cinza, preto};

typedef struct 
{
	int inicio,conclusao;
}timestamps;

typedef struct 
{
	short *cor;
	short *prd;
	int *dist;
	timestamps *t;
	fila f;
}BUSCA;


//funções da busca em largura
void cria_bfs(BUSCA *BUSCA, int n);
BUSCA bfs(GRAFO *g, int origem);
void imprime_caminho(BUSCA b, int origem, int atual);

//funcoes da busca em profundidade
void cria_dfs(BUSCA *d, int n);
void dfs_visit(BUSCA d, GRAFO *g, int i, int *time, lista *l);
BUSCA dfs(GRAFO *g, int origem, lista *l);




#endif