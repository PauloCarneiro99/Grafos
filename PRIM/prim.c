#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "matriz_adj.h"
#include "prim.h"


int menorPeso(int *key, unsigned char *inserido, GRAFO *g)
{
   int min = INT_MAX, min_indice;
 
   for (int v = 0; v < g->n; v++)
     if (inserido[v] == 0 && key[v] < min){
         min = key[v];
         min_indice = v;
     }

   return min_indice;
}

//Funcao que imprime as arestas contidas na arvore MST
void printPRIM(int *temp, int*parent, GRAFO *g){
	for(int i=1; i< g->n; i++){
     	if(parent[temp[i]] < temp[i])
     		printf("(%d,%d) ", parent[temp[i]], temp[i]);
     	else
     		printf("(%d,%d) ", temp[i],parent[temp[i]]);
     }
     printf("\n");
}


void primMST(GRAFO *g)
{
     int *parente = malloc(sizeof(int)*g->n);
     int *chave = malloc(sizeof(int)*g->n);  
     int *temp = malloc(sizeof(int)*g->n);
     unsigned char *inserido = calloc(sizeof(unsigned char),g->n); //vetor que checa se o vertice ja foi inserida, inicialmente todos sao falsos ( == 0)
     int *adj;
     int **graph = g->mat;
 
     for (int i = 0; i < g->n; i++){ //inicializando todas as chaves com o maior valor do inteiro, para que assim na hora de comaparar se eh menor
     //pela primeira vez, sempre sera verdadeiro
        chave[i] = INT_MAX;
    }
 
     chave[0] = 0;     
     parente[0] = -1; 
 
     for (int k = 0; k < g->n; k++)
     {
        int u = menorPeso(chave, inserido, g); //pegando o proximo vertice, cuja a aresta contem o menor peso
        inserido[u] = 1; //marcando u como inserido na arvore MST
        temp[k] = u;
 		adj = vertices_ajd(g,u); //pegando todas os vertices que sao adjacentes ao vertice u

        for (int v = 1; v < adj[0] + 1; v++){ //comeca em um pois adj[0] contem o tamanho do vetor de adj
          if(inserido[adj[v]] == 0 && graph[u][adj[v]] <  chave[adj[v]]){
             parente[adj[v]]  = u;
             chave[adj[v]] = graph[u][adj[v]];
          }
        }
     }


     printPRIM(temp, parente, g);
     //liberando o espaco alocado para o algoritmo
     free(temp);
     free(chave);
     free(inserido);
     free(parente);
}
