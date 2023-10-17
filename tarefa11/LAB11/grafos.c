#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int encontra_distancia(int *dist, int *visitado, int NV) {
    int i, menor = -1, primeiro = 1;
    for (i = 0; i < NV; i++) {
        if (dist[i] >= 0 && visitado[i] == 0) {
            if (primeiro) {
                menor = i;
                primeiro = 0;
            } else {
                if (dist[menor] > dist[i]) {
                    menor = i;
                }
            }
        }
    }
}
    


void menor_caminho(p_grafo mapa, int vertice_ini, int *ant, float *dist) {
    int i, count, NV, ind, *visitado, u;
    count = NV = mapa->n;
    visitado = malloc(NV * sizeof(int));
    for (i = 0; i < NV; i++) {
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[vertice_ini] = 0;
    while (count > 0)
    {
        u = encontra_distancia(dist, visitado, NV);
        if (u == -1) {
            break;
        }
        visitado[u] = 1;
        count--;
        for (i = 0; i < mapa->adjacencia[u]; i++) {
            ind = mapa->adjacencia
        }
    }
    free(visitado);


}

p_no insere_na_lista(p_no lista, int vertice, int n, int C) {
    int i;
    p_no novo = malloc(sizeof(struct no));
    for (i = (n - 1) - C; i < n; i++) {
        if (vertice == i) {
            novo->v = vertice;
            novo->identificador = 0;
            lista->prox = novo;
            novo->prox = NULL;
            return lista;
        }
    }
    novo->v = vertice;
    novo->identificador = 1;
    lista->prox = novo;
    novo->prox = NULL;
    return lista;
}

p_grafo criar_grafo(int n, int C, int P) {
    p_no vertices_iniciais = malloc(sizeof(struct no));
    int i, j;
    p_grafo g = malloc(sizeof(struct grafo));
    g->n = n;
    g->adjacencia = malloc(n * sizeof(p_no));
    for (i = 0; i < n; i++) {
        if (i == (n - 1) - C) {
            for (j = i; j < n; j++) {
                vertices_iniciais->v = j;
                vertices_iniciais->identificador = 0;
                g->adjacencia[j] = vertices_iniciais;
            }
            break;
        } else {
            vertices_iniciais->v = i;
            vertices_iniciais->identificador = 1;
            g->adjacencia[i] = vertices_iniciais;
        }
    }
    return g;

}

int main() {
    int i, j, C, P, E, vertice_1, vertice_2, quant_operacoes, vertice_ini, vertice_fim, *pai;
    char operacao;
    scanf("%d", &C);
    scanf("%d", &P);
    p_grafo mapa;
    mapa = criar_grafo(C + P, C, P);
    scanf("%d", &E);
    for (i = 0; i < E; i++) {
        scanf("%d", &vertice_1);
        scanf("%d", &vertice_2);
        mapa->adjacencia[vertice_1] = insere_na_lista(mapa->adjacencia[vertice_1], vertice_2, C + P, C);
        mapa->adjacencia[vertice_2] = insere_na_lista(mapa->adjacencia[vertice_2], vertice_1, C + P, C);
    }
    scanf("%d", &quant_operacoes);
    for (i = 0; i < quant_operacoes; i++) {
        scanf(" %c", &operacao);
        if (operacao == 'D') {
            scanf("%d", &vertice_ini);
            scanf("%d", &vertice_fim);
        
        }
    }
   









}