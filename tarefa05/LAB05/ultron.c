#include <stdio.h>
#include <stdlib.h>
#include "ultron.h"

void imprimir(ultron sistema, int k, int **matriz) {
    /*Função que imprimi as matrizes após as operações e quando está na ultima operação, indicado por k,
    ela imprimi, além da ultima matriz, a frase requisitada*/

    int i, j;
    for (i = 0; i < sistema.n_linha; i++) {
        for (j = 0; j < sistema.n_coluna; j++) {
            if (j == (sistema.n_coluna -1)) {
                printf("%d \n", matriz[i][j]);
            } else {
                printf("%d ", matriz[i][j]);
            }
        }
        if (i == (sistema.n_linha - 1)) {
            printf("###\n");
        }
    }
    if (k == (sistema.quant_op - 1)) {
        printf("COMBINACAO MATRICIAL FINALIZADA!\n");
    }
}

int **remover_coluna(ultron sistema, int **matriz) {
    /*Função que aloca uma matriz com a coluna removida. Logo após todo o processo, a função retorna essa
    matriz modificada para a função principal*/

    int i, j, indicador = 0, coluna_removida, **matriz_modificada;
    scanf("%d", &coluna_removida);
    matriz_modificada = malloc((sistema.n_linha) * sizeof(int *));
    for (i = 0; i < sistema.n_linha; i++) {
        matriz_modificada[i] = malloc((sistema.n_coluna - 1) * sizeof(int));
        for (j = 0; j < (sistema.n_coluna - 1); j++) {
            if (j != coluna_removida) {
                matriz_modificada[i][j] = matriz[i][j + indicador];
            } else {
                indicador = 1;
                matriz_modificada[i][j] = matriz[i][j + indicador];
            }
        }
        indicador = 0;
    }
    return matriz_modificada;
}

int **remover_linha(ultron sistema, int **matriz) {
    /*Função que aloca uma matriz com a linha removida. Logo após todo o processo, a função retorna essa
    matriz modificada para a função principal*/

    int i, j, indicador = 0, linha_removida, **matriz_modificada;
    scanf("%d", &linha_removida);
    matriz_modificada = malloc((sistema.n_linha - 1) * sizeof(int *));
    for (i = 0; i < (sistema.n_linha - 1); i++) {
        matriz_modificada[i] = malloc(sistema.n_coluna * sizeof(int));
        if (i != linha_removida) {
            for (j = 0; j < sistema.n_coluna; j++) {
                matriz_modificada[i][j] = matriz[i + indicador][j];
            }   
        } else {
            indicador = 1;
            for (j = 0; j < sistema.n_coluna; j++) {
                matriz_modificada[i][j] = matriz[i + indicador][j];
            } 
        }
    }
    return matriz_modificada;
}

int **adicionar_coluna(ultron sistema, int **matriz) {
    /*Função que aloca uma matriz com a coluna adicionda da operação, fazendo a ordenação das linhas da matriz com 
    o bubble sort. Logo após, todo esse processo a função retorna a matriz modificada para a função principal.*/

    int i, j, l, valor, aux, **matriz_modificada;
    matriz_modificada = malloc((sistema.n_linha) * sizeof(int *));
    for (i = 0; i < sistema.n_linha; i++) {
        matriz_modificada[i] = malloc((sistema.n_coluna + 1) * sizeof(int));
        for (j = 0; j < (sistema.n_coluna + 1); j++) {
            if (j == sistema.n_coluna) {
                scanf("%d", &valor);
                matriz_modificada[i][j] = valor;
            } else {
                matriz_modificada[i][j] = matriz[i][j];
            }
        }
        for (j = 0; j < sistema.n_coluna; j++) {
            for (l = 0; l < sistema.n_coluna; l++) {
                if (matriz_modificada[i][l] > matriz_modificada[i][l + 1]) {
                    aux = matriz_modificada[i][l + 1];
                    matriz_modificada[i][l + 1] = matriz_modificada[i][l];
                    matriz_modificada[i][l] = aux;
                }
            }
        }
    }
    return matriz_modificada;
}

int **adicionar_linha(ultron sistema, int **matriz) {
    /*Função que aloca uma matriz com a linha adicionada da operação. Logo após todo o processo 
    de inserção da nova linha ela retorna essa matriz modifcada para a função principal.*/

    int i, j, valor, **matriz_modificada;
    matriz_modificada = malloc((sistema.n_linha + 1) * sizeof(int *));
    for (i = 0; i < (sistema.n_linha + 1); i++) {
        matriz_modificada[i] = malloc(sistema.n_coluna * sizeof(int));
        if (i == sistema.n_linha) {
            for (j = 0; j < sistema.n_coluna; j++) {
                scanf("%d", &valor);
                matriz_modificada[i][j] = valor;
            }
        } else {
            for (j = 0; j < sistema.n_coluna; j++) {
                matriz_modificada[i][j] = matriz[i][j];
            }
        }
    }
    return matriz_modificada;
}

void modificar_matriz(ultron sistema, int **matriz, int **matriz_modificada, int k) {
    /*Função que recebe a matriz anterior e a modificada por quaisquer das operações desse problema. A partir disso,
    ela faz uma cópia para a matriz anterior, fazendo com que ela atualize. Por fim, a função encaminha o processo para
    a impressão da nova matriz.*/

    int i, j;
    for (i = 0; i < sistema.n_linha; i++) {
        matriz[i] = malloc(sistema.n_coluna * sizeof(int));
        for (j = 0; j < sistema.n_coluna; j++) {
            matriz[i][j] = matriz_modificada[i][j];
        }
    }
    imprimir(sistema, k, matriz);
}


