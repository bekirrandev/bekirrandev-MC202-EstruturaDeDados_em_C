typedef struct 
{
    int n_linha, n_coluna, quant_op;
} ultron;

void imprimir(ultron sistema, int k, int **matriz);

int **remover_coluna(ultron sistema, int **matriz);

int **remover_linha(ultron sistema,  int **matriz);

int **adicionar_coluna(ultron sistema, int **matriz);

int **adicionar_linha(ultron sistema, int **matriz);

void modificar_matriz(ultron sistema, int **matriz, int **matriz_modificada, int k);



