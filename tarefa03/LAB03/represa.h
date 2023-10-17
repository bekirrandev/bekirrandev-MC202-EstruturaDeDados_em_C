#define MAX1 100
#define MAX2 1000

typedef struct
{
    char nome_represa[MAX1];
    float nivel_max;
    int quant_medidas;
    int medidas_nivel[MAX2];
    int media;
} represa;

represa leitura_dados(int T, represa represas_lidas[]);

int identificador_medida_superior(represa dado);

void imprimir_dados(represa dado, int indicador_limite_superado);

void removedor_numero(char nome_represa[]);

void removedor_string(char nome_represa[]);

void verificador_underline(char nome_represa[]);

void verificador_letras_minusculas(char nome_represa[]);

void alterar_dados_represa(represa represas[], int T);