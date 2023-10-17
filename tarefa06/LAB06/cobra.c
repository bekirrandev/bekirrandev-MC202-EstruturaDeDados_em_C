#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cobra.h"


void modifica_lista_d(p_no lista, int k, int z, int nlinha, int ncoluna) {
    /*Função que faz a cobra andar para direita na matriz. Aqui quando há esse movimento se guarda as posicoes anteriores ao movimento. Alem disso, na ultima iteração da recursao verifica se 
    a posicao da cabeça da cobra (primeira lista) não está coincidindo com a ultima parte do corpo da cobra, porque daí ja sinaliza game over e a ultima parte do corpo não troca de posicao*/

    p_no aux;
    lista->x_anterior = lista->x;
    lista->y_anterior = lista->y;
    if (lista->anterior == NULL && lista->proximo == NULL) {
        if (lista->y == (ncoluna - 1)) {
            lista->y = 0;
        } else {
            lista->y++;
        }
        
    } else {
        if (lista->proximo) {
            if (lista->anterior == NULL) {
                if (lista->y == (ncoluna - 1)) {
                    lista->y = 0;
                } else {
                    lista->y++;
                }
                modifica_lista_d(lista->proximo, lista->x_anterior, lista->y_anterior, nlinha, ncoluna);
            } else {
                lista->x = k;
                lista->y = z;
                modifica_lista_d(lista->proximo, lista->x_anterior, lista->y_anterior, nlinha, ncoluna);
            }
        } else {
            aux = lista;
            while (aux->anterior != NULL)
            {
                aux = aux->anterior;
            }
            if (lista->x == aux->x && lista->y == aux->y) {
                return;
            } else {
                lista->x = k;
                lista->y = z;
            }
        }
    }
}

void modifica_lista_a(p_no lista, int k, int z, int nlinha, int ncoluna) {
    /*Função que faz a cobra andar para esquerda na matriz. Aqui quando há esse movimento se guarda as posicoes anteriores ao movimento. Alem disso, na ultima iteração da recursao verifica se 
    a posicao da cabeça da cobra (primeira lista) não está coincidindo com a ultima parte do corpo da cobra, porque daí ja sinaliza game over e a ultima parte do corpo não troca de posicao*/

    p_no aux;
    lista->x_anterior = lista->x;
    lista->y_anterior = lista->y;
    if (lista->anterior == NULL && lista->proximo == NULL) {
        if (lista->y == 0) {
            lista->y = (ncoluna - 1);
        } else {
            lista->y--;
        }
    } else {
        if (lista->proximo) {
            if (lista->anterior == NULL) {
                if (lista->y == 0) {
                    lista->y = (ncoluna - 1);
                } else {
                    lista->y--;
                }
                modifica_lista_a(lista->proximo, lista->x_anterior, lista->y_anterior, nlinha, ncoluna);
            } else {
                lista->x = k;
                lista->y = z;
                modifica_lista_a(lista->proximo, lista->x_anterior, lista->y_anterior, nlinha, ncoluna);
            }
        } else {
            aux = lista;
            while (aux->anterior != NULL)
            {
                aux = aux->anterior;
            }
            if (lista->x == aux->x && lista->y == aux->y) {
                return;
            } else {
                lista->x = k;
                lista->y = z;
            }
        }
    }

}

void modifica_lista_s(p_no lista, int k, int z, int nlinha, int ncoluna) {
    /*Função que faz a cobra andar para baixo na matriz. Aqui quando há esse movimento se guarda as posicoes anteriores ao movimento. Alem disso, na ultima iteração da recursao verifica se 
    a posicao da cabeça da cobra (primeira lista) não está coincidindo com a ultima parte do corpo da cobra, porque daí ja sinaliza game over e a ultima parte do corpo não troca de posicao*/

    p_no aux;
    lista->x_anterior = lista->x;
    lista->y_anterior = lista->y;
    if (lista->anterior == NULL && lista->proximo == NULL) {
        if (lista->x == (nlinha - 1)) {
            lista->x = 0;
        } else {
            lista->x++;
        }  
    } else {
        if (lista->proximo) {
            if (lista->anterior == NULL) {
                if (lista->x == (nlinha - 1)) {
                    lista->x = 0;
                } else {
                    lista->x++;
                }
                modifica_lista_s(lista->proximo, lista->x_anterior, lista->y_anterior, nlinha, ncoluna);
            } else {
                lista->x = k;
                lista->y = z;
                modifica_lista_s(lista->proximo, lista->x_anterior, lista->y_anterior, nlinha, ncoluna);
            }
        } else {
            aux = lista;
            while (aux->anterior != NULL)
            {
                aux = aux->anterior;
            }
            if (lista->x == aux->x && lista->y == aux->y) {
                return;
            } else {
                lista->x = k;
                lista->y = z;
            }
        }
    }
}

void modifica_lista_w(p_no lista, int k, int z, int nlinha, int ncoluna) {
    /*Função que faz a cobra andar para cima na matriz. Aqui quando há esse movimento se guarda as posicoes anteriores ao movimento. Alem disso, na ultima iteração da recursao verifica se 
    a posicao da cabeça da cobra (primeira lista) não está coincidindo com a ultima parte do corpo da cobra, porque daí ja sinaliza game over e a ultima parte do corpo não troca de posicao*/

    p_no aux;
    lista->x_anterior = lista->x;
    lista->y_anterior = lista->y;
    if (lista->anterior == NULL && lista->proximo == NULL) {
        if (lista->x == 0) {
            lista->x = (nlinha - 1);
        } else {
            lista->x--;
        }
    } else {
        if (lista->proximo) {
            if (lista->anterior == NULL) {
                if (lista->x == 0) {
                    lista->x = (nlinha - 1);
                } else {
                    lista->x--;
                }
                modifica_lista_w(lista->proximo, lista->x_anterior, lista->y_anterior, nlinha, ncoluna);
            } else {
                lista->x = k;
                lista->y = z;
                modifica_lista_w(lista->proximo, lista->x_anterior, lista->y_anterior, nlinha, ncoluna);
            }
        } else {
            aux = lista;
            while (aux->anterior != NULL)
            {
                aux = aux->anterior;
            }
            if (lista->x == aux->x && lista->y == aux->y) {
                return;
            } else {
                lista->x = k;
                lista->y = z;
            }
        }
    }
}

void verificar_game_over(p_no lista, int x, int y, int *vetor) {
    /*Função que verifica se a primeira lista (cabeça da cobra) está na mesma posicao que alguma lista posterior (alguma parte da cobra). Usei um vetor para armazemnar a sinalização de game over (v[0] = 1)*/

    if (lista->anterior == NULL) {
        verificar_game_over(lista->proximo, lista->x, lista->y, vetor);
    } else {
        if (lista->proximo != NULL) {
            if (lista->x == x && lista->y == y) {
                vetor[0] = 1;
                return;
            } else {
                verificar_game_over(lista->proximo, x, y, vetor);
            }
        } else {
            if (lista->x == x && lista->y == y) {
                vetor[0] = 1;
            } else {
                vetor[0] = 0;
            }
        }
    }
}

int verificar_you_win(int **matriz, int nlinha, int ncoluna) {
    /*Função que verifica se todas as posicões da matriz tem conteudo igual a 1, caso sim a cobra ganha o jogo*/

    int i, j, contador = 0;
    for (i = 0; i < nlinha; i++) {
        for (j = 0; j < ncoluna; j++) {
            if (matriz[i][j] == 1) {
                contador++;
            }
        }
    }
    if (contador == (nlinha * ncoluna)) {
        return 1;
    } else {
        return 0;
    }

}

void printar_matriz(int **matriz, int nlinha, int ncoluna) {
    /*Função que imprime a matriz depois da execução de algum movimento ou depois da inserção de uma fruta*/

    int i, j;
    for (i = 0; i < nlinha; i++) {
        for (j = 0; j < ncoluna; j++) {
            if (j == ncoluna - 1) {
                if (matriz[i][j] == 0) {
                    printf("%c \n", '_');
                } else if (matriz[i][j] == 1) {
                    printf("%c \n", '#');
                } else if (matriz[i][j] == -1) {
                    printf("%c \n", '*');
                }
            } else {
                if (matriz[i][j] == 0) {
                    printf("%c ", '_');
                } else if (matriz[i][j] == 1) {
                    printf("%c ", '#');
                } else if (matriz[i][j] == -1) {
                    printf("%c ", '*');
                }
            }
        }
        if (i == nlinha - 1) {
            printf("\n");
        }
    }
}

p_no adicionar_elemento(p_no lista) {
    /*Função que adiciona uma nova lista (uma nova parte do corpo da cobra) a lista, essa lista é setada na ultima posicao da lista ligada*/

    p_no novo, aux;
    novo = malloc(sizeof(struct no));
    if (lista->anterior == NULL && lista->proximo == NULL) {
        novo->x = lista->x_anterior;
        novo->y = lista->y_anterior;
        novo->x_anterior = lista->x_anterior;
        novo->y_anterior = lista->y_anterior;
        lista->proximo = novo;
        novo->anterior = lista;
        novo->proximo = NULL;
    } else {
        aux = lista;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        novo->x = aux->x_anterior;
        novo->y = aux->y_anterior;
        novo->x_anterior = aux->x_anterior;
        novo->y_anterior = aux->y_anterior;
        aux->proximo = novo;
        novo->anterior = aux;
        novo->proximo = NULL;
    }
    return lista;
}

void modificar_matriz(p_no lista, int **matriz, int nlinha, int ncoluna, int comeu) {
    /*Função que altera a matriz a cada movimento da cobra. No caso ela atualiza seus valores baseado nos valores ja modificados das listas, ou seja, muda os valores de cada posicao da matriz setando 0 quando não
    há nenhuma parte do corpo da cobra e 1 quando há parte (lista) da cobra naquela posicao. Se a cobra comeu a fruta quando executou algum movimento aumentamos o tamanho da cobra seteando 1 na posicao da ultima 
    lista ligada + 1*/

    if (lista->anterior == NULL && lista->proximo == NULL) {
        matriz[lista->x_anterior][lista->y_anterior] = 0;
        if (matriz[lista->x][lista->y] == -1) {
            lista = adicionar_elemento(lista);
            matriz[lista->x][lista->y] = 1;
            modificar_matriz(lista->proximo, matriz, nlinha, ncoluna, 1);
        } else {
            matriz[lista->x][lista->y] = 1;
        }
    } else {
        if (lista->proximo) {
            if (lista->anterior == NULL) {
                matriz[lista->x_anterior][lista->y_anterior] = 0;
                if (matriz[lista->x][lista->y] == -1) {
                    lista = adicionar_elemento(lista);
                    matriz[lista->x][lista->y] = 1;
                    modificar_matriz(lista->proximo, matriz, nlinha, ncoluna, 1);
                } else {
                    matriz[lista->x][lista->y] = 1;
                    modificar_matriz(lista->proximo, matriz, nlinha, ncoluna, 0);
                }
                
            } else {
                matriz[lista->x_anterior][lista->y_anterior] = 0;
                matriz[lista->x][lista->y] = 1;
                modificar_matriz(lista->proximo, matriz, nlinha, ncoluna, comeu);
            }
        } else {
            if (comeu == 1) {
                matriz[lista->x][lista->y] = 1;
            } else {
                matriz[lista->x_anterior][lista->y_anterior] = 0;
                matriz[lista->x][lista->y] = 1;
            }
            
        }
    }
}

p_no adicionar_elemento_inicial(p_no lista, int posicao_x, int posicao_y) {
    /*Função que adiciona a primeira lista na lista ligada. No caso, esse representa a cabeça da cobra que vai direcionar todo seu corpo no jogo*/

    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->x = posicao_x;
    novo->y = posicao_y;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void destruir_lista(p_no lista) {
    /*Função que libera a lista de tipo p_no*/

    if (lista != NULL) {
        destruir_lista(lista->proximo);
        free(lista);
    }
}