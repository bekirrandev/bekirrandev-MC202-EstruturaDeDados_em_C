#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultron.h"

int main() {
    /*Função principal que cria a struct ultron chamada sistema e recebe todas as entradas que indicam quais e quantas operações devem ser feitas.
    Essa função é muito importante, pois é aqui que a matriz e matriz_modificada são liberadas após seus usos nas operações. Isso faz com que consiguamos 
    modificar a matriz que é a matriz original a cada operação realizada*/
    
    int i, j, l, valor, quant_op, **matriz, **matriz_modificada;
    char operacao_entrada[4], operacao[] = "IN";
    char operacao_complemento;
    ultron sistema;
    scanf("%d", &sistema.n_linha);
    scanf("%d", &sistema.n_coluna);
    matriz = malloc(sistema.n_linha * sizeof(int *));
    for (i = 0; i < sistema.n_linha; i++) {
        matriz[i] = malloc(sistema.n_coluna * sizeof(int));
        for (j = 0; j < sistema.n_coluna; j++) {
            scanf("%d", &valor);
            matriz[i][j] = valor;
        }
    }
    scanf("%d", &quant_op);
    sistema.quant_op = quant_op;
    for (i = 0; i < quant_op; i++) {
        scanf("%s", operacao_entrada);
        if (strcmp(operacao_entrada, operacao) == 0) {
            scanf(" %c", &operacao_complemento);
            if (operacao_complemento == 'L') {
                matriz_modificada = adicionar_linha(sistema, matriz);
                for (l = 0; l < sistema.n_linha; l++) {
                    free(matriz[l]);
                }
                free(matriz);
                sistema.n_linha++;
                matriz = malloc(sistema.n_linha * sizeof(int *));
                modificar_matriz(sistema, matriz, matriz_modificada, i);
                for (l = 0; l < sistema.n_linha; l++) {
                    free(matriz_modificada[l]);
                }
                free(matriz_modificada);
            } else {
                matriz_modificada = adicionar_coluna(sistema, matriz);
                for (l = 0; l < sistema.n_linha; l++) {
                    free(matriz[l]);
                }
                free(matriz);
                sistema.n_coluna++;
                matriz = malloc(sistema.n_linha * sizeof(int *));
                modificar_matriz(sistema, matriz, matriz_modificada, i);
                for (l = 0; l < sistema.n_linha; l++) {
                    free(matriz_modificada[l]);
                }
                free(matriz_modificada);
            }
        } else {
            scanf(" %c", &operacao_complemento);
            if (operacao_complemento == 'L') {
                matriz_modificada = remover_linha(sistema, matriz);
                for (l = 0; l < sistema.n_linha; l++) {
                    free(matriz[l]);
                }
                free(matriz);
                sistema.n_linha--;
                matriz = malloc(sistema.n_linha * sizeof(int *));
                modificar_matriz(sistema, matriz, matriz_modificada, i);
                for (l = 0; l < sistema.n_linha; l++) {
                    free(matriz_modificada[l]);
                }
                free(matriz_modificada);
            } else {
                matriz_modificada = remover_coluna(sistema, matriz);
                for (l = 0; l < sistema.n_linha; l++) {
                    free(matriz[l]);
                }
                free(matriz);
                sistema.n_coluna--;
                matriz = malloc(sistema.n_linha * sizeof(int *));
                modificar_matriz(sistema, matriz, matriz_modificada, i);
                for (l = 0; l < sistema.n_linha; l++) {
                    free(matriz_modificada[l]);
                }
                free(matriz_modificada);
            }
        }
    }
}