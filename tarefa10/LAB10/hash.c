#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define M 113
#define tam 100

int hash(char *nome_processo) {
    /*Função que calcula o hash da chave do processo. Nesse caso eu optei por um M = 113, que respeita o fato de ser um numero primo. Sendo assim um otimo valor para o tamanho da minha tabela hash*/
    
    int i, n = 0;
    for (i = 0; i < strlen(nome_processo); i++) {
        n = (256 * n + nome_processo[i]) % M;
    }
    return n;
}

void rehash(vetor_processos tabela_hash, int posicao_tabela) {
    /*Função que reorganiza os processo a partir da posição do processo removido até a proxima posicação vazia da tabela, utilizando o hash das chaves.*/

    int i, j, nova_posicao;
    int aux;
    for (i = posicao_tabela + 1; i < M; i++) {
        if (tabela_hash[i].nulo != 0) {
            nova_posicao = hash(tabela_hash[i].nome_processo);
            if (nova_posicao != i) {
                if (tabela_hash[nova_posicao].nulo == 0) {
                    aux = tabela_hash[i].nulo;
                    tabela_hash[i].nulo = tabela_hash[nova_posicao].nulo;
                    tabela_hash[nova_posicao].nulo = aux;
                    tabela_hash[nova_posicao].ID = tabela_hash[i].ID;
                    tabela_hash[i].ID = 0;
                    tabela_hash[nova_posicao].nome_processo = tabela_hash[i].nome_processo;
                    tabela_hash[nova_posicao].tempo = tabela_hash[i].tempo;
                } else {
                    for (j = nova_posicao + 1; j < i; j++) {
                        if (tabela_hash[j].nulo == 0) {
                            aux = tabela_hash[j].nulo;
                            tabela_hash[j].nulo = tabela_hash[i].nulo;
                            tabela_hash[i].nulo = aux;
                            tabela_hash[j].ID = tabela_hash[i].ID;
                            tabela_hash[i].ID = 0;
                            tabela_hash[j].nome_processo = tabela_hash[i].nome_processo;
                            tabela_hash[j].tempo = tabela_hash[i].tempo;
                        }
                    }
                }
            }
        } else {
            tabela_hash[posicao_tabela].ID = 0;
            break;
        }
    }

}

int pesquisa_elemento(vetor_processos tabela_hash, int ID) {
    /*Faz uma busca linar por todo o vetor atrás do processso solicitado, utilizando para tal o identificado dele (ID)*/

    int i; 
    for (i = 0; i < M; i++) {
        if (tabela_hash[i].ID == ID) {
            return i;
        }
    }
    return -1;
}

void remover_processo(vetor_processos tabela_hash, int ID) {
    /*Função que busca na tabela (uma busca linear) o processo a ser removido, a partir de entao ele remove o processo sentando para a variavel nulo o valor de 0. Assim, o proximo passo é mandar para a função rehash
    para a realocação do elementos da tabela*/

    int posicao_tabela;
    posicao_tabela = pesquisa_elemento(tabela_hash, ID);
    if (posicao_tabela != -1) {
        tabela_hash[posicao_tabela].nulo = 0;
        rehash(tabela_hash, posicao_tabela);
    }
}

int procurar_nova_posicao(vetor_processos tabela_hash, int posicao_tabela) {
    /*Função que procura uma nova posicao dentro da tabela quando a posicao apontada pelo hash da chave já está ocupada. Desa forma, ele procura pela próxima posicao que nossa variável de sinalização está com o valor 0*/

    int i;
    if (tabela_hash[posicao_tabela].nulo == 0) {
        return posicao_tabela;
    } else {
        for (i = posicao_tabela + 1; i < M; i++) {
            if (tabela_hash[i].nulo == 0) {
                return i;
            } 
        }
        return i;
    }
    
}

void inicia_tabela(vetor_processos tabela_hash) {
    /*Função que inicia a tabela hash setando os valores da variavel nulo e ID em todas as posições do vetor. Apesar da inicialização dos dois, a variavel nulo indica se a posicao da tabela hash esta alocando conteudo*/

    int i;
    for (i = 0; i < M; i++) {
        tabela_hash[i].nulo = 0;
        tabela_hash[i].ID = 0;

    }
}
