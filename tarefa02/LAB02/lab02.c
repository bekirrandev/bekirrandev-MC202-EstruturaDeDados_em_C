#include <stdio.h>
#include <string.h>
#define MAX 100

void imprimir(int N, int matriz[][MAX], int referencia) {
    /*Função que imprime as matrizes das operações e utiliza o valor da referencia para saber se é a primeira matriz a ser imprimida para que, assim, seja printado a primeira linha vazia do teste*/
    
    int i, j;
    if (referencia == 0) {
        printf("\n");
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (j == (N - 1)) {
                printf("%d \n", matriz[i][j]);
            } else {
                printf("%d ", matriz[i][j]);
            }   
        }
        if (i == (N - 1)) {
            printf("\n");
        }
    }
}

void bordas_matriz_igual(int N, int matriz_X[][MAX], int referencia) {
    /*Função que realiza a mesma operação que a função: bordas_matriz_diferente, porém ela trata opreções de borda em que se tem duas matrizes iguais. Dessa forma, somente uma é colocada na operação e se constrói outra matriz
    para fazer as modificações de borda*/

    int i, j, matriz_Y[MAX][MAX];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == 0 || i == (N - 1) || j == 0 || j == (N - 1)) {
                matriz_Y[i][j] = matriz_X[i][j];
            } else {
                if (matriz_X[i][j] == 1) {
                    if (matriz_X[i - 1][j] == 1 && matriz_X[i + 1][j] == 1 && matriz_X[i][j + 1] == 1 && matriz_X[i][j - 1] == 1 && matriz_X[i + 1][j + 1] == 1 && matriz_X[i + 1][j - 1] == 1 && matriz_X[i - 1][j + 1] == 1 && matriz_X[i - 1][j - 1] == 1) {
                        matriz_Y[i][j] = 0;
                    } else {
                        matriz_Y[i][j] = matriz_X[i][j];
                    }
                } else {
                    matriz_Y[i][j] = matriz_X[i][j];
                }
            }   
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matriz_X[i][j] = matriz_Y[i][j];
        }
    }
    imprimir(N, matriz_Y, referencia);
}

void bordas_matriz_diferente(int N, int matriz_X[][MAX], int matriz_Y[][MAX], int referencia) {
    /*Função que realiza a operação de bordas, ou seja, nas posições da matriz onde se tem o valor 1 e em volta dessa posição todos os valores são 1 também zeramos a posição. Isso repeitando a regra de que a primeira e ultima linha, assim
    como a primeira e ultima coluna, não participam da operação por serem periféricas. Aqui todas as direções são levadas em consideração, inclusive as diagonais.
    Foi seprado essa função em dois: bordas_matriz_diferente e bordas_matriz_igual, pois quando se tem duas matrizes iguais sendo recebidas nos parâmetros da função, as modifcações de um refletem na outra. Dessa forma, a função
    para matrizes iguais recebe somente uma matriz como parâmetro e cria outra para ser modificada*/

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == 0 || i == (N - 1) || j == 0 || j == (N - 1)) {
                matriz_Y[i][j] = matriz_X[i][j];
            } else {
                if (matriz_X[i][j] == 1) {
                    if (matriz_X[i - 1][j] == 1 && matriz_X[i + 1][j] == 1 && matriz_X[i][j + 1] == 1 && matriz_X[i][j - 1] == 1 && matriz_X[i + 1][j + 1] == 1 && matriz_X[i + 1][j - 1] == 1 && matriz_X[i - 1][j + 1] == 1 && matriz_X[i - 1][j - 1] == 1) {
                        matriz_Y[i][j] = 0;
                    } else {
                        matriz_Y[i][j] = matriz_X[i][j];
                    }
                } else {
                    matriz_Y[i][j] = matriz_X[i][j];
                }
            }   
        }
    }
    imprimir(N, matriz_Y, referencia);
}

void mult_mat(int N, int matriz_X[][MAX], int matriz_Y[][MAX], int matriz_Z[][MAX], int referencia) {
    /*Função que realiza a multipĺicação de matrizes de acordo com a lieteratura de algebra linear, ou seja, linha com coluna multiplicando os elementos correspondentes e depois somando 
    tudo e guardando na posição da matriz Z indicada pela linha e coluna da operação*/

    int i, j, k, elem_aux = 0, valor;
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            for (j = 0; j < N; j++) {
                valor = matriz_X[i][j] * matriz_Y[j][k];
                if (elem_aux == 1 && valor == 1) {
                    elem_aux = 1;
                } else {
                    elem_aux += valor;
                }
            }
            matriz_Z[i][k] = elem_aux;
            elem_aux = 0;
        }
    }
    imprimir(N, matriz_Z, referencia);
}

void mult_elem(int N, int matriz_X[][MAX], int matriz_Y[][MAX], int matriz_Z[][MAX], int referencia) {
    /*Função que realiza a multipĺicação termo a termo como na soma de matrizes, ou seja, é uma multiplicação atipica e diferente da literatura de algebra linear*/

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matriz_Z[i][j] = matriz_X[i][j] * matriz_Y[i][j];
        }
    }
    imprimir(N, matriz_Z, referencia);
}

void soma(int N, int matriz_X[][MAX], int matriz_Y[][MAX], int matriz_Z[][MAX], int referencia) {
    /*Função que realiza a soma termo a termo das matrizes X e Y guardando na matriz Z, porém como estamos trabalhando com matrizes binarias as somas maiores que 1 são iguais a 1*/

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (matriz_X[i][j] == 1 && matriz_Y[i][j] == 1) {
                matriz_Z[i][j] = 1;
            } else {
                matriz_Z[i][j] = matriz_X[i][j] + matriz_Y[i][j];
            }
        }
    }
    imprimir(N, matriz_Z, referencia);
}

void transposta(int N, int matriz_X[][MAX], int matriz_Y[][MAX], int referencia) {
    /*Função que realiza a operação de transposição de matrizes como indicado nas literaturas de algebra linear, ou seja, trocando as linhas por colunas*/

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matriz_Y[i][j] = matriz_X[j][i];
        }
    }
    imprimir(N, matriz_Y, referencia);
}

void construtor_matriz(int N, int matriz[][MAX]) {
    /*Função que constrói as matrizes A e B respeitando as faixas de três colunas de uns e zeros*/

    int i = 3, elemento = 1, m, n;
    while (i <= N) {
        for (n = (i - 3); n < i; n++) {
            for (m = 0; m < N; m++) {
                matriz[m][n] = elemento;
            }
        }
        if (elemento == 1) {
            elemento = 0;
        } else {
            elemento = 1;
        }
        i+= 3;
    }
}

int main() {
    /*Função principal que primeiramente lê a quantidade de operações a serem feitas. Logo após constrói as matrizes A e B na função construtor_matriz. Depois com a biblioteca string.h identifica qual operação vai ser feita
    respeitando a ordenação na entrada desses dados. Tendo identificado a operação, destinamos para a função correspondente, porém para isso tevemos que utilizar todas as combinações possiveis de ordenação ao passa para as 
    funções das operações. Dessa forma, a operação transposta por exemplo como temos 2 posssibilidades de parametro na função tivemos que tratar de 4 posssibilidades de arranjos de parâmetros*/

    int i = 0, N, O, matriz_A[MAX][MAX], matriz_B[MAX][MAX];
    char letra1, letra2, letra3;
    char operacao[11], operacao1[] = "TRANSPOSTA", operacao2[] = "SOMA", operacao3[] = "MULTI_ELEM", operacao4[] = "MULTI_MAT", operacao5[] = "BORDAS";
    scanf("%d", &N);
    construtor_matriz(N, matriz_A);
    construtor_matriz(N, matriz_B);
    scanf("%d", &O);
    while (i < O) {
        scanf("%s",operacao);
        if (strcmp(operacao, operacao1) == 0) {
            scanf("%c", &letra1);
            while (letra1 == ' ') {
                scanf("%c", &letra1);
            }
            scanf("%c", &letra2);
            while (letra2 == ' ') {
                scanf("%c", &letra2);
            }
            if (letra1 == 'A' && letra2 == 'B') {
                if (i == 0) {
                    transposta(N, matriz_A, matriz_B, 0);
                } else {
                    transposta(N, matriz_A, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'A') {
                if (i == 0) {
                    transposta(N, matriz_B, matriz_A, 0);
                } else {
                    transposta(N, matriz_B, matriz_A, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'A') {
                if (i == 0) {
                    transposta(N, matriz_A, matriz_A, 0);
                } else {
                    transposta(N, matriz_A, matriz_A, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'B') {
                if (i == 0) {
                    transposta(N, matriz_B, matriz_B, 0);
                } else {
                    transposta(N, matriz_B, matriz_B, 1);
                }
            }
        }
        if (strcmp(operacao, operacao2) == 0) {
            scanf("%c", &letra1);
            while (letra1 == ' ') {
                scanf("%c", &letra1);
            }
            scanf("%c", &letra2);
            while (letra2 == ' ') {
                scanf("%c", &letra2);
            }
            scanf("%c", &letra3);
            while (letra3 == ' ') {
                scanf("%c", &letra3);
            }
            if (letra1 == 'A' && letra2 == 'B' && letra3 == 'A') {
                if (i == 0) {
                    soma(N, matriz_A, matriz_B, matriz_A, 0);
                } else {
                    soma(N, matriz_A, matriz_B, matriz_A, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'B' && letra3 == 'B') {
                if (i == 0) {
                    soma(N, matriz_A, matriz_B, matriz_B, 0);
                } else {
                    soma(N, matriz_A, matriz_B, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'A' && letra3 == 'A') {
                if (i == 0) {
                    soma(N, matriz_B, matriz_A, matriz_A, 0);
                } else {
                    soma(N, matriz_B, matriz_A, matriz_A, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'A' && letra3 == 'B') {
                if (i == 0) {
                    soma(N, matriz_B, matriz_A, matriz_B, 0);
                } else {
                    soma(N, matriz_B, matriz_A, matriz_B, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'A' && letra3 == 'A') {
                if (i == 0) {
                    soma(N, matriz_A, matriz_A, matriz_A, 0);
                } else {
                    soma(N, matriz_A, matriz_A, matriz_A, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'A' && letra3 == 'B') {
                if (i == 0) {
                    soma(N, matriz_A, matriz_A, matriz_B, 0);
                } else {
                    soma(N, matriz_A, matriz_A, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'B' && letra3 == 'B') {
                if (i == 0) {
                    soma(N, matriz_B, matriz_B, matriz_B, 0);
                } else {
                    soma(N, matriz_B, matriz_B, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'B' && letra3 == 'A') {
                if (i == 0) {
                    soma(N, matriz_B, matriz_B, matriz_A, 0);
                } else {
                    soma(N, matriz_B, matriz_B, matriz_A, 1);
                }
            }
        }
        if (strcmp(operacao, operacao3) == 0) {
            scanf("%c", &letra1);
            while (letra1 == ' ') {
                scanf("%c", &letra1);
            }
            scanf("%c", &letra2);
            while (letra2 == ' ') {
                scanf("%c", &letra2);
            }
            scanf("%c", &letra3);
            while (letra3 == ' ') {
                scanf("%c", &letra3);
            }
            if (letra1 == 'A' && letra2 == 'B' && letra3 == 'A') {
                 if (i == 0) {
                    mult_elem(N, matriz_A, matriz_B, matriz_A, 0);
                 } else {
                    mult_elem(N, matriz_A, matriz_B, matriz_A, 1);
                 }
            }
            if (letra1 == 'A' && letra2 == 'B' && letra3 == 'B') {
                if (i == 0) {
                    mult_elem(N, matriz_A, matriz_B, matriz_B, 0);
                } else {
                    mult_elem(N, matriz_A, matriz_B, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'A' && letra3 == 'A') {
                if (i == 0) {
                    mult_elem(N, matriz_B, matriz_A, matriz_A, 0);
                } else {
                    mult_elem(N, matriz_B, matriz_A, matriz_A, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'A' && letra3 == 'B') {
                if (i == 0) {
                    mult_elem(N, matriz_B, matriz_A, matriz_B, 0);
                } else {
                    mult_elem(N, matriz_B, matriz_A, matriz_B, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'A' && letra3 == 'A') {
                if (i == 0) {
                    mult_elem(N, matriz_A, matriz_A, matriz_A, 0);
                } else {
                    mult_elem(N, matriz_A, matriz_A, matriz_A, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'A' && letra3 == 'B') {
                if (i == 0) {
                    mult_elem(N, matriz_A, matriz_A, matriz_B, 0);
                } else {
                    mult_elem(N, matriz_A, matriz_A, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'B' && letra3 == 'B') {
                if (i == 0) {
                    mult_elem(N, matriz_B, matriz_B, matriz_B, 0);
                } else {
                    mult_elem(N, matriz_B, matriz_B, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'B' && letra3 == 'A') {
                if (i == 0) {
                    mult_elem(N, matriz_B, matriz_B, matriz_A, 0);
                } else {
                    mult_elem(N, matriz_B, matriz_B, matriz_A, 1);
                }
            }
        }
        if (strcmp(operacao, operacao4) == 0) {
            scanf("%c", &letra1);
            while (letra1 == ' ') {
                scanf("%c", &letra1);
            }
            scanf("%c", &letra2);
            while (letra2 == ' ') {
                scanf("%c", &letra2);
            }
            scanf("%c", &letra3);
            while (letra3 == ' ') {
                scanf("%c", &letra3);
            }
            if (letra1 == 'A' && letra2 == 'B' && letra3 == 'A') {
                if (i == 0) {
                    mult_mat(N, matriz_A, matriz_B, matriz_A, 0);
                } else {
                    mult_mat(N, matriz_A, matriz_B, matriz_A, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'B' && letra3 == 'B') {
                if (i == 0) {
                    mult_mat(N, matriz_A, matriz_B, matriz_B, 0);
                } else {
                    mult_mat(N, matriz_A, matriz_B, matriz_B, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'A' && letra3 == 'A') {
                if (i == 0) {
                    mult_mat(N, matriz_A, matriz_A, matriz_A, 0);
                } else {
                    mult_mat(N, matriz_A, matriz_A, matriz_A, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'A' && letra3 == 'B') {
                if (i == 0) {
                    mult_mat(N, matriz_A, matriz_A, matriz_B, 0);
                } else {
                    mult_mat(N, matriz_A, matriz_A, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'B' && letra3 == 'B') {
                if (i == 0) {
                    mult_mat(N, matriz_B, matriz_B, matriz_B, 0);
                } else {
                    mult_mat(N, matriz_B, matriz_B, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'B' && letra3 == 'A') {
                if (i == 0) {
                    mult_mat(N, matriz_B, matriz_B, matriz_A, 0);
                } else {
                    mult_mat(N, matriz_B, matriz_B, matriz_A, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'A' && letra3 == 'A') {
                if (i == 0) {
                    mult_mat(N, matriz_B, matriz_A, matriz_A, 0);
                } else {
                    mult_mat(N, matriz_B, matriz_A, matriz_A, 1);
                }
            }
        }
        if (strcmp(operacao, operacao5) == 0) {
            scanf("%c", &letra1);
            while (letra1 == ' ') {
                scanf("%c", &letra1);
            }
            scanf("%c", &letra2);
            while (letra2 == ' ') {
                scanf("%c", &letra2);
            }
            if (letra1 == 'A' && letra2 == 'B') {
                if (i == 0) {
                    bordas_matriz_diferente(N, matriz_A, matriz_B, 0);
                } else {
                    bordas_matriz_diferente(N, matriz_A, matriz_B, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'A') {
                if (i == 0) {
                    bordas_matriz_diferente(N, matriz_B, matriz_A, 0);
                } else {
                    bordas_matriz_diferente(N, matriz_B, matriz_A, 1);
                }
            }
            if (letra1 == 'A' && letra2 == 'A') {
                if (i == 0) {
                    bordas_matriz_igual(N, matriz_A, 0);
                } else {
                    bordas_matriz_igual(N, matriz_A, 1);
                }
            }
            if (letra1 == 'B' && letra2 == 'B') {
                if (i == 0) {
                    bordas_matriz_igual(N, matriz_B, 0);
                } else {
                    bordas_matriz_igual(N, matriz_B, 1);
                }
            }
        }
        i++;
    }
}