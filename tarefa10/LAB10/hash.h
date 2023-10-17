#define M 113
#define tam 100

typedef struct 
{
    int ID, tempo, nulo;
    char *nome_processo;
} processo;

typedef processo vetor_processos[M];

int hash(char *nome_processo);

void rehash(vetor_processos tabela_hash, int posicao_tabela);

int pesquisa_elemento(vetor_processos tabela_hash, int ID);

void remover_processo(vetor_processos tabela_hash, int ID);

int procurar_nova_posicao(vetor_processos tabela_hash, int posicao_tabela);

void inicia_tabela(vetor_processos tabela_hash);
