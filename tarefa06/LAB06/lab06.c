#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cobra.h"


int main() {
    /*Função principal que inicializa a lista e a matriz verifica quais os comandos a serem dados para a movimentação da cobra e verifica se o jogo foi vencido ou nao. Alem disso, libera todos os seus
    vetores ao fim do processo*/

    int i, j, k = 0, aux = 0, contador = 0, posicao_cobra_x, posicao_cobra_y, posicao_fruta_x, posicao_fruta_y, nlinha, ncoluna, **matriz, *vetor_identificacao;
    vetor_identificacao = malloc(sizeof(int));
    vetor_identificacao[0] = 0;
    p_no lista = NULL;
    char identificacao1[6], identificacao2[6], identificacao3[] = "FRUTA", comando[6], comando1[] = "w", comando2[] = "s", comando3[] = "a", comando4[] = "d";
    scanf("%d", &nlinha);
    scanf("%d", &ncoluna);
    matriz = malloc(nlinha * sizeof(int *));
    for (i = 0; i < nlinha; i++) {
        matriz[i] = malloc(ncoluna * sizeof(int));
        for (j = 0; j < ncoluna; j++) {
            matriz[i][j] = 0;
        }
    }
    scanf("%s", identificacao1);
    scanf("%d", &posicao_fruta_x);
    scanf("%d", &posicao_fruta_y);
    scanf("%s", identificacao2);
    scanf("%d", &posicao_cobra_x);
    scanf("%d", &posicao_cobra_y);
    matriz[posicao_fruta_x][posicao_fruta_y] = -1;
    matriz[posicao_cobra_x][posicao_cobra_y] = 1;
    printar_matriz(matriz, nlinha, ncoluna);
    lista = adicionar_elemento_inicial(lista, posicao_cobra_x, posicao_cobra_y);
    scanf("%s", comando);
    while (aux == 0)
    {
        if (strcmp(comando, identificacao3) == 0) {
            scanf("%d", &posicao_fruta_x);
            scanf("%d", &posicao_fruta_y);
            matriz[posicao_fruta_x][posicao_fruta_y] = -1;
            printar_matriz(matriz, nlinha, ncoluna);
            scanf("%s", comando);
        }
        while (strcmp(comando, identificacao3) != 0)
        {
            if (strcmp(comando, comando1) == 0) {
                modifica_lista_w(lista, lista->x, lista->y, nlinha, ncoluna);
            } else if (strcmp(comando, comando2) == 0) {
                modifica_lista_s(lista, lista->x, lista->y, nlinha, ncoluna);
            } else if (strcmp(comando, comando3) == 0) {
                modifica_lista_a(lista, lista->x, lista->y, nlinha, ncoluna);
            } else if (strcmp(comando, comando4) == 0) {
                modifica_lista_d(lista, lista->x, lista->y, nlinha, ncoluna);
            }
            for (i = 0; i < nlinha; i++) {
                for (j = 0; j < ncoluna; j++) {
                    if (matriz[i][j] == 1) {
                        contador++;
                    }
                }
            }
            if (contador > 2) {
                k = verificar_you_win(matriz, nlinha, ncoluna);
                if (k == 1) {
                    printf("YOU WIN\n");
                    aux = 1;
                    break;
                } else {
                    verificar_game_over(lista, lista->x, lista->y, vetor_identificacao);
                    if (vetor_identificacao[0] == 1) {
                        printar_matriz(matriz, nlinha, ncoluna);
                        printf("GAME OVER\n");
                        aux = 1;
                        break;
                    }
                }
            }
            modificar_matriz(lista, matriz, nlinha, ncoluna, 0);
            printar_matriz(matriz, nlinha, ncoluna);
            scanf("%s", comando);
            contador = 0;
        }
    }
    free(vetor_identificacao);
    for (i = 0; i < nlinha; i++) {
        free(matriz[i]);
    }
    free(matriz);
    destruir_lista(lista);
}