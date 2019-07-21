

#include <stdio.h>
#include <stdlib.h>

#define STRMAX 	100

struct LIVROS {
    char nomel[STRMAX + 1];
    char autor[STRMAX + 1];
    int pg;
    double valor;
};

/* Prototype das funções */
/* Função tamanho (mesmo que strlen) */
int tamanho(char *);

/* Função lestring publicada no artigo do Viva o Linux */
int lestring(char[], int);

/* Função para realizar a leitura de livros */
int lelivros(struct LIVROS[], int, int);

int calcPg(struct LIVROS *, double *);


int main(int argc, char *argv[])
{
    struct LIVROS *l;           // Entra esta no lugar
	
	
    int ql;                     // quantidade real de livros
    int tnomel;                 // para guardar o tamanho do maior nomel digitado
    int tautor;                 // para guardar o tamanho do maior nome de autor digitado
    int tpag = 10;              // tamanho do campo pagina na impressao
    int tvalor = 13;            // tamanho do campo valor na impressao
    int i, t;
    double totvalor, custo;
    int totpg;

    ql = 0;
    if (argc >= 2) {
        ql = atoi(argv[1]);
        if (ql <= 0) {
            printf("ERRO %s.\n", argv[1]);
            printf("# ERRO: quantidade de livros deve ser maior que 0\n");
        }
    }

    l = NULL;
    /* Primeiro: vendo se já tem ql maior que zero, vindo do main. Alocando
     * este se ok (poderia ter sido feito lá no if (argc... mas minha tática
     * aqui é mudar o mínimo possivel o código original do T22 estático */
    if (ql > 0) {
        l = (struct LIVROS *) malloc(ql * sizeof(struct LIVROS));
        if (l == NULL) {
            printf("ERRO malloc: %d\n", ql);
            printf("# NÃO FOI POSSÍVEL ALOCAR %d livros.\n", ql);
            /* Mensagem com #. para não boicotar os testes */
            printf("FIM.\n");
            return (1);
        }
    }

    while (l == NULL) {         // pode entrar este no lugar, enquanto não pode alocar
        printf("# Quantos livros você quer digitar:\n");
        if (scanf("%d", &ql) == 0) {
            printf("ERRO: entrada invalida.\n");
            printf("# ERRO. Digitou lixo\n");
            while (fgetc(stdin) != '\n');
            continue;
        }
        if (ql <= 0) {
            printf("ERRO %d.\n", ql);
            printf("# ERRO: quantidade de livros deve ser maior que 0\n");
            continue;           /* colocando um continue aqui para evitar else neste if
                                   agora se for negativou ou zero, já volta para ler novamente */
        }

        l = (struct LIVROS *) malloc(ql * sizeof(struct LIVROS));
        if (l == NULL) {
            printf("ERRO malloc: %d\n", ql);
            printf("FIM.\n");
            printf("# ERRO malloc: não pode alocar %i livros\n", ql);
            return (1);
        }
    }

    printf("# Alocou com sucesso %i LIVROS\n", ql);


    lelivros(l, ql, STRMAX + 1);
    printf("\n# ---- FIM DO CADASTRO DE %d LIVROS ----\n\n", ql);

    /* Laco para descobrir os maiores nomes e autores para usar na impressão
     * Ok, ok. A função lelivros podia ter calculado isso. Mas ai ela teria
     * que retornar uma struct (possível) ou receber muitos outros parâmetros
     * e ainda por referência */
    tnomel = tautor = -1;
    for (i = 0; i < ql; i++) {
        t = tamanho(l[i].nomel);
        tnomel = (t > tnomel) ? t : tnomel;
        t = tamanho(l[i].autor);
        tautor = (t > tautor) ? t : tautor;
    }
    /* Imprimindo o cabeçalho do relatório. Pegando quantos bytes o 
     * cabeçalho usou (retorno do printf) 
     * */
    printf("  ");
    t = printf("%-*s %-*s %*s %*s\n", tnomel, "Nome do livro", tautor, "Nome do autor", tpag,
               "Paginas", tvalor, "Valor");
    /* Observe acima o enorme uso do * para passar o tamanho ao printf */

    /* Imprimindo uma linha só com -. Mas quantos '-' precisa?
     * A variável t tem a quantidade ;-)
     * */
    printf("  ");
    for (i = 0; i < t; i++) {
        printf("-");
    }
    printf("\n");
    totvalor = 0;
    /* Imprimindo cada livro e calculando o total em reais */
    //tnomel=tpag=tautor=3;

    totpg = 0;
    calcPg(NULL, &custo);
    for (i = 0; i < ql; i++) {
        printf("  %-*s %-*s %*d R$ %*.2lf\n", tnomel, l[i].nomel, tautor, l[i].autor, tpag, l[i].pg,
               tvalor - 3, l[i].valor);
        totvalor += l[i].valor;
        totpg = totpg + l[i].pg;
        calcPg(&l[i], &custo);
    }

    printf("\n  Total de todos os %d livros: R$%10.2lf\n", ql, totvalor);
    printf("  Total de paginas: %d\n", totpg);
    printf("  Custo por pagina: R$ %.2lf\n", custo);
    printf("\n# Custo por pagina calcudo no main: R$ %.2lf\n", (double) totvalor / totpg);

    free(l);
    printf("\nFIM.\n");
    return (0);
}

int lelivros(struct LIVROS l[], int ql, int maxstr)
{
    int i;

    printf("# Digite os dados para %d livros\n", ql);

    for (i = 0; i < ql; i++) {
        printf("\n# --- Livro [%d] ---\n", i);
        printf("# Nome do livro:\n");
        lestring(l[i].nomel, maxstr);

        printf("\n# Nome do autor:\n");
        lestring(l[i].autor, maxstr);

        l[i].pg = -1;
        while (l[i].pg < 0) {
            printf("\n# Quantas páginas:\n");
            if (scanf("%d", &l[i].pg) == 0) {
                printf("ERRO: entrada invalida.\n");
                printf("# ERRO. Digitou lixo\n");

                /* little fflush ;-) */
                while (fgetc(stdin) != '\n');
                continue;
            }
        }
        l[i].valor = -1;
        while (l[i].valor < 0) {
            printf("\n# Valor em reais:\n");
            if (scanf("%lf", &l[i].valor) == 0) {
                printf("ERRO: entrada invalida.\n");
                printf("# ERRO. Digitou lixo\n");
                while (fgetc(stdin) != '\n');
                continue;
            }
        }
    }
    return (i);
}

int tamanho(char s[])
{
    int i = 0;
    for (i = 0; s[i]; i++);
    return (i);
}

int lestring(char s[], int max)
{
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);
        /* Pulando o ENTER. O car 13 só é final de linha em textos
         * padrão DOS (e o DOS tem também o 10)*/
        if (letra == 13) {
            i--;
            continue;
        }
        /* Texto DOS e LINUX tem 10 no final de linha (LINE FEED) */
        if ((letra == 10) && (i == 0)) {
            i = i - 1;
            continue;
        }
        if (letra == 10) {
            break;
        }
        s[i] = letra;
    }
    s[i] = 0;
    return (i);
}
int calcPg(struct LIVROS *l, double *media)
{
    static int totpg = 0;
    static double valor = 0;

    if (l == NULL) {
        totpg = 0;
        valor = 0;
        *media = 0;
        return (0);
    }

    totpg = totpg + l->pg;
    valor = valor + l->valor;
    *media = valor / totpg;

    return (totpg);
}
