
typedef struct no *p_no;

struct no 
{
    int x, y, x_anterior, y_anterior;
    p_no proximo;
    p_no anterior;
};


void modifica_lista_d(p_no ponteiro, int k, int z, int nlinha, int ncoluna);

void modifica_lista_a(p_no ponteiro, int k, int z, int nlinha, int ncoluna);

void modifica_lista_s(p_no ponteiro, int k, int z, int nlinha, int ncoluna);

void modifica_lista_w(p_no ponteiro, int k, int z, int nlinha, int ncoluna);

void verificar_game_over(p_no ponteiro, int x, int y, int *vetor);

int verificar_you_win(int **matriz, int nlinha, int ncoluna);

void printar_matriz(int **matriz, int nlinha, int ncoluna);

p_no adicionar_elemento(p_no lista);

void modificar_matriz(p_no ponteiro, int **matriz, int nlinha, int ncoluna, int comeu);

p_no adicionar_elemento_inicial(p_no lista, int posicao_x, int posicao_y);

void destruir_lista(p_no lista);

