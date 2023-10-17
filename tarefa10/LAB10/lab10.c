#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define M 113
#define tam 100


int main() {
    /*Função principal que recebe os parâmetros inicais e inicia a tabela hash. Identifica as operações de inserção (I), remoção (R), consulta (C), tempo de processo (T) e as executa.*/
    
    int i, n, ID, posicao_tabela, tempo, nova_posicao;
    char operacao, *nome_processo;
    vetor_processos tabela_hash;
    inicia_tabela(tabela_hash);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c", &operacao);
        if (operacao == 'I') {
            scanf("%d", &ID);
            nome_processo = malloc(tam * sizeof(char));
            scanf("%s", nome_processo);
            posicao_tabela = hash(nome_processo);
            if (tabela_hash[posicao_tabela].nulo == 0) {
                tabela_hash[posicao_tabela].ID = ID;
                tabela_hash[posicao_tabela].nome_processo = malloc(tam * sizeof(char));
                tabela_hash[posicao_tabela].nome_processo = nome_processo;
                scanf("%d", &tempo);
                tabela_hash[posicao_tabela].tempo = tempo;
                tabela_hash[posicao_tabela].nulo = 1;
                printf("PROCESSO %d INSERIDO!\n", tabela_hash[posicao_tabela].ID);
            } else {
                nova_posicao = procurar_nova_posicao(tabela_hash, posicao_tabela);
                tabela_hash[nova_posicao].ID = ID;
                tabela_hash[nova_posicao].nome_processo = malloc(tam * sizeof(char));
                tabela_hash[nova_posicao].nome_processo = nome_processo;
                scanf("%d", &tempo);
                tabela_hash[nova_posicao].tempo = tempo;
                tabela_hash[nova_posicao].nulo = 1;
                printf("PROCESSO %d INSERIDO!\n", tabela_hash[nova_posicao].ID);
            }
        } else if (operacao == 'R') {
            scanf("%d", &ID);
            remover_processo(tabela_hash, ID);
            printf("PROCESSO %d REMOVIDO!\n", ID);
        } else if (operacao == 'C') {
            scanf("%d", &ID);
            posicao_tabela = pesquisa_elemento(tabela_hash, ID);
            if (posicao_tabela == -1) {
                printf("PROCESSO %d NAO ENCONTRADO!\n", ID);
            } else {
                printf("PROCESSO %d: ", ID);
                printf("%s\n", tabela_hash[posicao_tabela].nome_processo);
            }
        } else if (operacao == 'T') {
            scanf("%d", &ID);
            posicao_tabela = pesquisa_elemento(tabela_hash, ID);
            printf("TEMPO DO PROCESSO %d: ", ID);
            printf("%d DIAS.\n", tabela_hash[posicao_tabela].tempo);
        }
    }
    free(nome_processo);
    printf("FINALIZADO!\n");
}