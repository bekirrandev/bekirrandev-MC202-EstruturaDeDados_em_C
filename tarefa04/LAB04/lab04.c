#include <stdio.h>
#include <stdlib.h>

void imprimir_sub_tropa_elite(int *sub_tropa_elite, int tam) {
    /*Função que printa todos os valores do vetor sub_tropa_elite*/
    
    int i;
    printf("Sub-tropa Elite: ");
    for (i = 0; i < tam; i++) {
        if (i == tam - 1) {
            printf("%d \n", sub_tropa_elite[i]);
        } else {
            printf("%d ", sub_tropa_elite[i]);
        }
    }
    return;
}

void selecionar_sub_tropa_elite(int *vetor_concatenado, int n, int *quant_tropas) {
    /*Essa função utiliza a mesma lógica de maior vetor, já utilizado nesse programa, porém agora ele faz isso no vetor normalizado pela média dos valores do vetor
    concatenado que contem todas as subtropas fortes*/

    int i, k, j, somador = 0, media = 0, somador_media = 0, *vetor_normalizado, *sub_tropa_elite;
    int aux1 = 0, aux2 = 2, aux3 = 0, somador1 = 0, somador2 = 0, divisor = 0, subdivisao = 0, posicao1, posicao2;
    for (i = 0; i < n; i++) {
        somador += quant_tropas[i];
    }
    vetor_normalizado = malloc(somador * sizeof(int));
    for (i = 0; i < somador; i++) {
        somador_media += vetor_concatenado[i];
    }
    media = somador_media / somador;
    for (i = 0; i < somador; i++) {
        vetor_normalizado[i] = vetor_concatenado[i] - media;
    }
    for (i = 1; i <= somador; i++) {
        divisor = somador / i;
        subdivisao = somador / divisor;
        if (somador % i != 0) {
            subdivisao = i;
        }
        aux2 = subdivisao;
        aux1 = 0;
        for (k = 0; k < ((somador - subdivisao) + 1); k++) {
            if (subdivisao == 1) {
                for (j = aux1; j < aux2; j++) {
                    somador1 += vetor_normalizado[j]; 
                }
                if (j == 1) {
                    somador2 = somador1;
                    posicao1 = j - 1;
                    posicao2 = j - 1;
                } else {
                    if (somador1 > somador2) {
                        somador2 = somador1;
                        posicao1 = j - 1;
                        posicao2 = j - 1;
                    }
                }
                
                somador1 = 0;
                aux1 = j; 
                aux2 += subdivisao;
            } else {
                for (j = aux1; j < aux2; j++) {
                    somador1 += vetor_normalizado[j]; 
                }
                if (somador1 > somador2) {
                    somador2 = somador1;
                    posicao1 = j - subdivisao;
                    posicao2 = j - 1;
                }
                somador1 = 0;
                aux1 = j - aux3; 
                aux2++;
            }
        }
        aux3++;
    }
    if (posicao1 == posicao2) {
        sub_tropa_elite = malloc(sizeof(int));
        sub_tropa_elite[0] = vetor_concatenado[posicao1];
    } else {
        sub_tropa_elite = malloc(((posicao2 - posicao1) + 1) * sizeof(int));
        for (i = 0; i < ((posicao2 - posicao1) + 1); i++) {
            sub_tropa_elite[i] = vetor_concatenado[posicao1 + i];
        }
    }
    free(vetor_normalizado);
    imprimir_sub_tropa_elite(sub_tropa_elite, ((posicao2 - posicao1) + 1));
    free(sub_tropa_elite);
    return;
}

int *concatenar_vetor(int **sub_tropas_fortes, int n, int *quant_tropas) {
    /*Função que junta todos os vetores de subtropas fortes num vetor só, ou seja, retira todos os valores dos vetores da matriz sub_tropas_fortes e aloca
    num vetor aqui criado.*/

    int i, j, aux = 0, somador = 0, *vetor_concatendo;
    for (i = 0; i < n; i++) {
        somador += quant_tropas[i];
    }
    vetor_concatendo = malloc(somador * sizeof(int));
    for (i = 0; i < n; i++) {
        for (j = 0; j < quant_tropas[i]; j++) {
            vetor_concatendo[aux] = sub_tropas_fortes[i][j];
            aux++;
        }
    }
    return vetor_concatendo;
}

void selecionar_sub_tropa_forte(int *tropa, int q, int **sub_tropas_fortes, int indice, int *quant_tropas) {
    /*Essa função seleciona a subtropa forte utilizando o raciocinio do maior vetor dentro do vetor das subtropas. Logo após, ele armazena esse vetor de subtropas fortes na matriz
    sub_tropas_fortes com o auxilio das posicoes marcadas durante a execução da lógica.*/

    int i, j, k, aux1 = 0, aux2 = 2, aux3 = 0, somador1 = 0, somador2 = 0, divisor = 0, subdivisao = 0, posicao1, posicao2;
    for (i = 1; i <= q; i++) {
        divisor = q / i;
        subdivisao = q / divisor;
        if (q % i != 0) {
            subdivisao = i;
        }
        aux2 = subdivisao;
        aux1 = 0;
        for (k = 0; k < ((q - subdivisao) + 1); k++) {
            if (subdivisao == 1) {
                for (j = aux1; j < aux2; j++) {
                    somador1 += tropa[j]; 
                }
                if (j == 1) {
                    somador2 = somador1;
                    posicao1 = j - 1;
                    posicao2 = j - 1;
                } else {
                    if (somador1 > somador2) {
                        somador2 = somador1;
                        posicao1 = j - 1;
                        posicao2 = j - 1;
                    }
                }
                somador1 = 0;
                aux1 = j; 
                aux2 += subdivisao;
            } else {
                for (j = aux1; j < aux2; j++) {
                    somador1 += tropa[j]; 
                }
                if (somador1 > somador2) {
                    somador2 = somador1;
                    posicao1 = j - subdivisao;
                    posicao2 = j - 1;
                }
                somador1 = 0;
                aux1 = j - aux3; 
                aux2++;
            }
        }
        aux3++;
    } 
    if (posicao1 == posicao2) {
        quant_tropas[indice] = 1;
        sub_tropas_fortes[indice] = malloc(sizeof(int));
        sub_tropas_fortes[indice][0] = tropa[posicao1];
    } else {
        quant_tropas[indice] = (posicao2 - posicao1) + 1;
        sub_tropas_fortes[indice] = malloc(quant_tropas[indice] * sizeof(int));
        for (i = 0; i < quant_tropas[indice]; i++) {
            sub_tropas_fortes[indice][i] = tropa[posicao1 + i];
        }
    }
}

void imprimir_sub_tropa_forte(int **sub_tropas_fortes, int n, int *quant_tropas) {
    /*Função que printa os vetores de subtropas fortes utilizando o vetor quant_tropas para percorrer os elementos*/

    int i, j;
    for (i = 0; i < n; i++) {
        printf("Sub-tropa Forte %d: ", i + 1);
        for (j = 0; j < quant_tropas[i]; j++) {
            if (j == (quant_tropas[i] - 1)) {
                printf("%d \n", sub_tropas_fortes[i][j]);
            } else {
                printf("%d ", sub_tropas_fortes[i][j]);
            }
        }
    }
}

int main() {
    /*Essa função principal inicializa o programa com os vetores sub_tropas_fortes, quant_tropas, tropas e vetor concatenado. O vetor tropa vai ser onde
    vamos alocar os valores de casa subtropa, após isso, esse vetor ja é mandado para a função "selecionar_tropas_fortes" para a seleção das subtropas fortes da tropa. O vetor
    quant_tropas aloca valores relacionados aos tamanhos dos vetores de subtropas fortes armazenados na matriz "sub_tropas_fortes", para auxiliar oportunamente em passar por esse vetores. O
    vetor concatenado é um vetor que aloca todos os valores de subtropas fortes num unico vetor. Por fim, a matriz sub_tropas_fortes armazena todas as subtropas fortes linha a linha*/

    int n, i, q, j, exp, indice = 0, *tropa, *quant_tropas, **sub_tropas_fortes, *vetor_concatenado;
    scanf("%d", &n);
    sub_tropas_fortes = malloc(n * sizeof(int *));
    quant_tropas = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &q);
        tropa = malloc(q * sizeof(int));
        for (j = 0; j < q; j++) {
            scanf("%d", &exp);
            tropa[j] = exp;
        }
        selecionar_sub_tropa_forte(tropa, q, sub_tropas_fortes, indice, quant_tropas);
        indice++;
        free(tropa);
    }
    imprimir_sub_tropa_forte(sub_tropas_fortes, n, quant_tropas);
    vetor_concatenado = concatenar_vetor(sub_tropas_fortes, n, quant_tropas);
    selecionar_sub_tropa_elite(vetor_concatenado, n, quant_tropas);
    for (i = 0; i < n; i++) {
        free(sub_tropas_fortes[i]);
    }
    free(sub_tropas_fortes);
    free(quant_tropas);
    free(vetor_concatenado);
}