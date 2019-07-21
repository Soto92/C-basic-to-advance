
#include <stdio.h>


#define MAXFRASE 10000
#define SAIDA "AGORA EU QUERO TERMINAR"
/* Aposto que você não pensou em usar uma constante para a frase de saida 
 * */

/* Só copiei o V3 de 190322-exemplo2.c publicado */
int ES_strlen(char s[])
{
    int i;
    for (i = 0; s[i]; i++);
    return (i);
}

/* Tirado do 190322-exemplo2.c disponibilizado no classroom */
int ES_strncpy(char dst[], char ori[], int max)
{
    /* Copia ori para dst, respeitando max. 
     * Retorna quantidade de cars copiados
     * (que é o tamanho de dst)
     * */
    int i = 0;

    for (i = 0; ori[i]; i++) {
        if (i == (max - 1)) {
            break;
        }
        dst[i] = ori[i];
    }
    dst[i] = 0;
    return (i);                 // tamanho de dst
}

int ES_strcasecmp(char s1[], char s2[])
{
    char c1, c2;
    int i;

    for (i = 0; s1[i]; i++) {
        c1 = s1[i];
        c2 = s2[i];

        if ((c1 >= 'a') && (c1 <= 'z')) {
            c1 = c1 - 32;
            /* A "distância" entre uma letra maiúscula e sua equivalente
             * minúscula é 32. Do 'a' (97) para o 'A' (65) tem 32.
             * Então, se for letra minúscula, basta diminuir 32 para virar
             * maiúscula. Mas precisa ter certeza de que é minúscula. Um 
             * erro comum é diminuir sempre. Ai se a letra já é um 'A' (65)
             * ela vai virar um '!' (33) */
        }

        if ((c2 >= 'a') && (c2 <= 'z')) {
            c2 = c2 - 32;
        }
        if (c1 != c2) {
            return (c1 - c2);
        }
    }

    return (s1[i] - s2[i]);
    /* Só chega neste return se chegou ao final de s1.
     * Se chegou também no final de s2 elas são iguais
     * e irá retornar 0 - 0 = 0.
     * Se chegou no fim de s1 mas não de s2, a subtração
     * anterior será 0 - 'uma letra' e dará um número negativo
     * */
}

int main()
{
    char frase[MAXFRASE + 1];
    char maiorfrase[MAXFRASE + 1];
    int maior;
    int tot, i, tam;

    /* Opcionalmente podia ter criado uma string para a frase de saida e feito
     * 
     * ES_strncpy (fraseSaida, "AGORA EU QUERO TERMINAR", MAXFRASE);
     * 
     * Mas pra que gastar memória?
     * */

    printf("# Digite frases. Quantas quiser.\n");
    printf("# Para encerrar, digite \"%s\"\n", SAIDA);
    tot = 0;
    maior = 0;
    maiorfrase[0] = 0;

    do {
        fgets(frase, MAXFRASE, stdin);
        tam = ES_strlen(frase);
        /* Se o fgets leu um '\n', remove ele */
        if (frase[tam - 1] == '\n') {
            frase[--tam] = 0;
            /* E atualiza tam que deve ter o tamanho. É só diminuir 1.
             * Não precisa chamar strlen novamente
             * 
             * Claro que alguns se sentiriam mais confortáveis se vissem isso:
             *     tam = tam - 1;
             *     frase[tam] = 0;
             * */
        }

        /* Um equivoco na hora de analisar as necessidades fez alguns grupos
         * acharem que precisava transformar a string em maiúsculas (quem me
         * procurou teve a dúvida resolvida).
         * 
         * NÃO PRECISA. Porque eu realmente não quero ela transformada.
         * Só preciso comparar sem considerar case. Como faz a função
         * strcasecmp da string.h, como descrito na página 17 da apostila
         * de algoritmos II (mas que não pode usar. Então, implementa)
         */
        if (ES_strcasecmp(frase, SAIDA) == 0) {
            break;
        }
        tot++;
        if (tam >= maior) {
            maior = tam;
            ES_strncpy(maiorfrase, frase, MAXFRASE);
        }
        printf("\n# Digitado \"%s\" com %d caracteres\n", frase, tam);
        printf("%d\n", tam);
        printf("\n# Outra frase\n");
    } while (1);

    printf("\n# DIGITACAO ENCERRADA\n");
    printf("# Foram digitadas %d frases\n", tot);

    printf("\n%d\n", tot);
    printf("%d \"%s\"\n", maior, maiorfrase);
    printf("\n# FIM\n");
}
