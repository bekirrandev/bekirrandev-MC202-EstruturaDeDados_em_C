#include <stdio.h>
#include "represa.h"
#define MAX 1000

int main() {
    /*Função principal que lê a quantidade de represas do teste direciona para as função de leitura de dados e posteriormente alteração desses dados. Logo após, direciona para a função
    que identifica a ultrapassagem do limite máximo de armazenamento e, por fim, imprime os dados na função imprimir_dados.*/
    
    int T, i, indicador;
    represa represas_lidas[MAX];
    scanf("%d", &T);
    leitura_dados(T, represas_lidas);
    alterar_dados_represa(represas_lidas, T);
    for (i = 0; i < T; i++) {
        indicador = identificador_medida_superior(represas_lidas[i]);
        imprimir_dados(represas_lidas[i], indicador);
    }
}