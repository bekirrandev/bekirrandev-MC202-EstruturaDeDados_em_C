#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


int main() {
    /*Função que recebe os parâmetros e inicia a fila_processos. Logo após, aloca os processos da lista e depois executa os comandos ou de remoção ou de mudança de prioridade.*/
    
    int n, k = 0, n_comando, quant_prioridade, i, j, P, C;
    char comando;
    p_fp fila_processos;
    processos processo, *processos_maior_prioridade;
    scanf("%d", &n);
    fila_processos = cria_fila_processos(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &P);
        scanf("%d", &C);
        alocar_processos(fila_processos, P, C);
    }
    scanf("%d", &n_comando);
    for (i = 0; i < n_comando; i++) {
        scanf(" %c", &comando);
        if (comando == 'R') {
            scanf("%d", &quant_prioridade);
            processos_maior_prioridade = malloc(quant_prioridade * sizeof(processos));
            while (k < quant_prioridade)
            {
                processo = extrair_maior_prioridade(fila_processos);
                processos_maior_prioridade[k] = processo;
                k++;
            }
            k = 0;
            printf("PROCESSOS REMOVIDOS: ");
            for (j = 0; j < quant_prioridade; j++) {
                if (j == quant_prioridade - 1) {
                    printf("%d\n", processos_maior_prioridade[j].P);
                } else {
                    printf("%d ", processos_maior_prioridade[j].P);
                }
            }
            free(processos_maior_prioridade);
        } else if (comando == 'M') {
            scanf("%d", &P);
            scanf("%d", &C);
            modifica_prioridade(fila_processos, P, C);
        }
    }
    printf("FINALIZADO!\n");
    free(fila_processos->v);
    free(fila_processos);
}