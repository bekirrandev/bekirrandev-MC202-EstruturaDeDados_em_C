
typedef struct no *p_no;

struct no {
    int v;
    int identificador;
    p_no prox;
};

typedef struct grafo *p_grafo;

struct grafo {
    p_no *adjacencia;
    int n;
};