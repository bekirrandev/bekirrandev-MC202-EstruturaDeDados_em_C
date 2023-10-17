#include <stdio.h>
#include "represa.h"
#define MAX 1000

void removedor_numero(char nome_represa[]) {
    /*Função que remove os números ao final dos nomes. A execução se da por identifcar quantas vezes há a ocorrencia de um número do nome e, logo após, faz uma lógica parecida com a função removedor_string, 
    porém muda por percorrer o nome inicinado no indice do primeiro número encontrado*/
    
    int i = 0, k = 0, contador = 0;
    while (nome_represa[i] != '\0')
    {
        if (nome_represa[i] >= '0' && nome_represa[i] <= '9') {
            contador++;
        }
        i++;
    }
    while (k < contador)
    {
        nome_represa[i - 1] = nome_represa[i];
        k++;
        i--;
    }
}

void removedor_string(char nome_represa[]) {
    /*Função que remove o prefixo: 'represa_de_'. No caso ela identifica quais nomes tem esse prefixo e remove ele na lógica de substituição da letra atual pela letra posterior até o final do nome, fazendo isso 11 vezes (tamanho do prefixo)*/

    int i = 0, j = 0;
    if (nome_represa[0] == 'r' && nome_represa[1] == 'e' && nome_represa[2] == 'p' && nome_represa[3] == 'r' && nome_represa[4] == 'e' && nome_represa[5] == 's' && nome_represa[6] == 'a' && nome_represa[7] == '_' && nome_represa[8] == 'd' && nome_represa[9] == 'e' && nome_represa[10] == '_') {
        while (i < 11)
        {
            while (nome_represa[j] != '\0')
            {
                nome_represa[j] = nome_represa[j + 1]; 
                j++;
            }
            j = 0;
            i++;
        }
    }
}

void verificador_underline(char nome_represa[]) {
    /*Função que percorre todo o vetor em que está armazenado o nome da represa e procura o caracter underline e substitui por um espaço*/

    int i = 0;
    while (nome_represa[i] != '\0') 
    {
        if (nome_represa[i] == '_') {
            nome_represa[i] = ' ';
        }
        i++;
    }
}

void verificador_letras_minusculas(char nome_represa[]) {
    /*Função que retira as letras maiusculas. No caso elas são identificadas pela sua númeração na tabela ASCII. Quando identificada a númeração, por lógica, de acordo com a tabela, para a transformação 
    para seu correspondente minusculo é só somar 32.*/

    int i = 0;
    while (nome_represa[i] != '\0')
    {
        if (nome_represa[i] >= 'A' && nome_represa[i] <= 'Z') {
            nome_represa[i] = nome_represa[i] + 32;
        }
        i++;
    }
}

void alterar_dados_represa(represa represas[], int T) {
    /*Função que direciona os nomes das represas para serem alterados. Sendo assim, através das funções é retirado as letras maiúsculas, os números, o prefixo 'represa_de_' e os underlines*/

    int i;
    for (i = 0; i < T; i++) {
        verificador_letras_minusculas(represas[i].nome_represa);
        removedor_numero(represas[i].nome_represa);
        removedor_string(represas[i].nome_represa);
        verificador_underline(represas[i].nome_represa);
    }
}


void imprimir_dados(represa dado, int indicador_limite_superado) {
    /*Função que imprime os dados das represas. Dados esses ja modificador pela função alterar_dados_represa. Se o limite de nível máximo é ultrapassado por alguma medida ele imprime
    a frase indicada nessa função, caso contrário não imprime nada.*/

    printf("NOME: %s\n", dado.nome_represa);
    printf("QTD NIVEIS: %d\n", dado.quant_medidas);
    printf("MEDIA: %d\n", dado.media);
    if (indicador_limite_superado == 1) {
        printf("CAPACIDADE ACIMA DE 90%% DA MAXIMA!\n");
    }
    printf("#####\n");
}

int identificador_medida_superior(represa dado) {
    /*Função que delimita o limite de 90% de armazenamento e verifica no vetor de medidas de nível, armazenado no dado do tipo represa, se há alguma medida que ultrapassa esse limite.
    Aqui essa função retorna 1 caso alguma medida ultrapasse o limite e 0 caso o contrario*/

    int i;
    float limite = dado.nivel_max * 0.9;
    for (i = 0; i < dado.quant_medidas; i++) {
        if (dado.medidas_nivel[i] >= limite) {
            return 1;
        }
    }
    return 0;
}

represa leitura_dados(int T, represa represas_lidas[]) {
    /*Função que faz a leitura dos dados das represas e armazena num vetor do tipo represa, tipo esse que foi construído no arquivo represa.h.
    Logo após, ele retorna esse vetor para a função principal*/

    int i, j, somador = 0;
    represa dados_represa;
    for (i = 0; i < T; i++) {
        scanf("%s", dados_represa.nome_represa);
        scanf("%f", &dados_represa.nivel_max);
        scanf("%d", &dados_represa.quant_medidas);
        for (j = 0; j < dados_represa.quant_medidas; j++) {
            scanf("%d", &dados_represa.medidas_nivel[j]);
            somador += dados_represa.medidas_nivel[j];
        }
        dados_represa.media = somador / dados_represa.quant_medidas;
        somador = 0;
        represas_lidas[i] = dados_represa;
    }
    return represas_lidas[MAX];
}
