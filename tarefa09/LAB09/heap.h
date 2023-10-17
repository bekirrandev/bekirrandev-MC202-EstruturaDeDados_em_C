
typedef struct
{
    int P, C;
} processos;

typedef struct
{
    processos *v;
    int n, tam;
} FP;

typedef FP *p_fp;


void modifica_prioridade(p_fp fila_processos, int P, int C);

void desce_heap(p_fp fila_processos, int k);

processos extrair_maior_prioridade(p_fp fila_processos);

void sobe_heap(p_fp fila_processos, int k);

void alocar_processos(p_fp fila_processos, int P, int C);

p_fp cria_fila_processos(int tam);