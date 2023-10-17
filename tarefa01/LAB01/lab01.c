#include <stdio.h>
#define MAX 1000

/*Essa função diz respeito a quarta, e última, operação. Nela somente invertemos os vetor, para isso
é usado a estrutura de bobble sort para reorganizar o vetor. Primeiro é identificado se o tamanho 
do vetor é impar ou par, logo após, iteramos cada elemento fazendo a sua substituição usando o
elemento_aux.*/
void inversor_vetor(int u[], int T) {
    int i, elemento_aux;
    if (T % 2 != 0) {
        for (i = 0; i < (T / 2); i++) {
            elemento_aux = u[i];
            u[i] = u[(T - 1) - i];
            u[(T - 1) - i] = elemento_aux;
        }
    } else {
        for (i = 0; i < (T / 2); i++) {
            elemento_aux = u[i];
            u[i] = u[(T - 1) - i];
            u[(T - 1) - i] = elemento_aux;
        }
    }
}

/*Essa função diz respeito a terceira operação. Nela criamos um vetor identico (vetor_aux) 
ao vetor original para girar o vetor em cada posição. Ou seja, a cada elemento iterado esse
elemento é trocado pelo elemento de posição anterior a ele, isso usando o vetor_aux como 
auxiliador.*/
void movimento_ciclico(int u[], int T, int P) {
    int i = 0, k, vetor_aux[MAX];
    while (i < P) {
        for (k = 0; k < T; k++) {
            vetor_aux[k] = u[k];
        }
        for (k = 0; k < T; k++) {
            if (k == 0) {
                u[k] = vetor_aux[T - 1];
            } else {
                u[k] = vetor_aux[k - 1];
            }
        }
        i++;
    }
}

/*Essa é a função que diz respeito a segunda operação. Nela é feito a multiplacação de M
nos elementos em posição ímpar no vetor u*/
void multiplicacao_mobius(int u[], int T, int M) {
    int i;
    for (i = 0; i < T; i++) {
        if ((i % 2) != 0) {
            u[i] = u[i] * M;
        }
    }

}

/*Essa é a função que diz respeito a primeira operação. Nela é identificado qual 
dos elementos do vetor u estão no vetor b, caso isso não tenha correspondencia o elemento 
é zerado*/
void conjunto_banner(int u[], int b[], int T, int B) {
    int j, i;
    for (j = 0; j < T; j++) {
        for (i = 0; i < B; i++){
            if (u[j] == b[i]) {
                break;
            }
            if (i == (B - 1)) {
                u[j] = 0;
            }
        }
    }
}

/*Essa função faz a impressão do vetor u modifcado a cada operação realizada. De modo que, o 
último elemento de cada vetor tem um \n adicionado.*/
void imprimir(int u[], int T) {
    int i;
    for (i = 0; i < T; i++) {
        if (i == (T - 1)) {
            printf("%d \n", u[i]);
        } else {
            printf("%d ", u[i]);
        }       
    }
}

/*A função main é a responsável por identificar o vetor de entrada (u)
e encaminhar para a função, de acordo com o número da operação. Além disso, 
ela imprime o resultados do vetor u modificado pelas operações*/
int main() {
    int i, T, P, B, M, k = 0, quant_op, operacao, u[MAX], b[MAX];
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d", &u[i]);
    }
    scanf("%d", &quant_op);
    while (k < quant_op) {
        scanf("%d", &operacao);
        if (operacao == 1) {
            scanf("%d", &B);
            for (i = 0; i < B; i++) {
                scanf("%d", &b[i]);
            }
            conjunto_banner(u, b, T, B);
            imprimir(u, T);
        }
        if (operacao == 2) {
            scanf("%d", &M);
            multiplicacao_mobius(u, T, M);
            imprimir(u, T);
        }
        if (operacao == 3) {
            scanf("%d", &P);
            movimento_ciclico(u, T, P);
            imprimir(u, T);
        }
        if (operacao == 4) {
            inversor_vetor(u, T);
            imprimir(u, T);
        }
        k++;
    }
}

