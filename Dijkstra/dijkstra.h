#ifndef DIJKSTRA
#define DIJKSTRA

typedef struct{
	int* dist;
	int* parent;
}dijk; 

void imprime_caminho(dijk b, int origem, int atual);
void inicia(int vertice, dijk *d);
void dijkstra(GRAFO *g, int origem, int destino);

#endif