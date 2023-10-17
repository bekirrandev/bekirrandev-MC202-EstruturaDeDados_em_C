#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)

void desce_heap(p_fp fila_processos, int k) {
    /*função que utiliza a lógica de min-heap, ou seja, o maior valor de prioridade são os ultimos da lista. Desssa forma, a função desce aquele processo de maior C*/
    
    int maior_filho;
    processos aux;
    if (F_ESQ(k) < fila_processos->n) {
        maior_filho  = F_ESQ(k);
        if ((F_DIR(k) < fila_processos->n)) {
            if (fila_processos->v[F_ESQ(k)].C != fila_processos->v[F_DIR(k)].C) {
                if (fila_processos->v[F_ESQ(k)].C > fila_processos->v[F_DIR(k)].C) {
                    maior_filho = F_DIR(k);
                }
            } else {
                if (fila_processos->v[F_ESQ(k)].P < fila_processos->v[F_DIR(k)].P) {
                    maior_filho = F_DIR(k);
                }
            }
        }
        if (fila_processos->v[k].C != fila_processos->v[maior_filho].C) {
            if (fila_processos->v[k].C > fila_processos->v[maior_filho].C) {
                aux = fila_processos->v[maior_filho];
                fila_processos->v[maior_filho] = fila_processos->v[k];
                fila_processos->v[k] = aux;
                desce_heap(fila_processos, maior_filho);
            }
        } else {
            if (fila_processos->v[k].P < fila_processos->v[maior_filho].P) {
                aux = fila_processos->v[maior_filho];
                fila_processos->v[maior_filho] = fila_processos->v[k];
                fila_processos->v[k] = aux;
                desce_heap(fila_processos, maior_filho);
            }
        }
    }

}

processos extrair_maior_prioridade(p_fp fila_processos) {
    /*Função que vai fazer uma busca do elemento de maior prioridade, que no caso é a raiz da lista. Ao localizar a raiz ele remove o elemento diminuindo o tamanho de fila_processos e realocando os processo descendo no heap*/
    
    processos aux;
    processos processo_maior_prioridade = fila_processos->v[0];
    aux = fila_processos->v[fila_processos->n - 1];
    fila_processos->v[fila_processos->n - 1] = fila_processos->v[0];
    fila_processos->v[0] = aux;
    fila_processos->n--;
    desce_heap(fila_processos, 0);
    return processo_maior_prioridade;
}

void sobe_heap(p_fp fila_processos, int k) {
    /*Função que utiliza a lógica de min-heap, ou seja, a maior prioridade tem valor minimo (a maior prioridade tem o menor C). Dessa forma, a função sobe na lista o processo de menor C, com o menor C sendo a raiz*/

    processos aux;
    if (k > 0) {
        if (fila_processos->v[PAI(k)].C != fila_processos->v[k].C) {
            if (fila_processos->v[PAI(k)].C > fila_processos->v[k].C) {
                aux = fila_processos->v[PAI(k)];
                fila_processos->v[PAI(k)] = fila_processos->v[k];
                fila_processos->v[k] = aux;
                sobe_heap(fila_processos, PAI(k));
            }
        } else {
            if (fila_processos->v[PAI(k)].P < fila_processos->v[k].P) {
                aux = fila_processos->v[PAI(k)];
                fila_processos->v[PAI(k)] = fila_processos->v[k];
                fila_processos->v[k] = aux;
                sobe_heap(fila_processos, PAI(k));
            }
        }
    }

}

void modifica_prioridade(p_fp fila_processos, int P, int C) {
    /*Função que muda a prioridade (variavel C) do processo solicitado. Isso acontece a depender da nova prioridade inserida, caso seja maior que a sua atual o processo vai para a função sobe_heap, 
    caso contrario ela vai para a função desce_heap*/

    int i;
    for (i = 0; i < fila_processos->tam; i++) {
        if (fila_processos->v[i].P == P) {
            if (fila_processos->v[i].C < C) {
                fila_processos->v[i].C = C;
                desce_heap(fila_processos, i);
            } else {
                fila_processos->v[i].C = C;
                sobe_heap(fila_processos, i);
            }
            break;
        }
    }
}

void alocar_processos(p_fp fila_processos, int P, int C) {
    /*Função que adiciona processos a fila_processo. faz isso salvando os valores de prioridade(C) e identificacao (P). Após isso é incrementado o tamanho de fila_processos. E por fim direciona o processo para
    a função sobe no heap que vai alocar o processo de acordo com sua prioridade*/

    fila_processos->v[fila_processos->n].P = P;
    fila_processos->v[fila_processos->n].C = C;
    fila_processos->n++;
    sobe_heap(fila_processos, (fila_processos->n - 1));
}


p_fp cria_fila_processos(int tam) {
    /*Função que inicia a fila de processos, variavel do tipo p_fp. Essa variavel é um vetor de strct que guada as informaçẽos da quantidade de processos, sua identificacao e sua prioridade na lista*/

    p_fp fila_processos = malloc(sizeof(FP));
    fila_processos->v = malloc(tam * sizeof(processos));
    fila_processos->n = 0;
    fila_processos->tam = tam;
    return fila_processos;
}


