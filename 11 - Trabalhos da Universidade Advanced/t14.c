

#include <stdio.h>
#include <stdlib.h>

#define VTAM 100000

/* Função que verifica se num já existe no vetor v de tamanho t
 * Retoruna o indice do vetor onde está num se existir 
 * e retorna -1 caso num não esteja em v
 * */
int achou(int v[], int t, int num)
{
    int i;
    for (i = 0; i < t; i++) {
        if (num == v[i]){
            return (i);
		}
    }
    return (-1);
}

/* Função que compara dois números, de acordo com o critério, e retorna:
 *   0 se ambos são iguais
 * > 0 se n1 for maior (de acordo com o critério)
 * < 0 se n1 for menor
 * 
 * Para o T14 o critério é:
 * Pares antes, do menor ao maior
 * Impares depois, do maior ao menor
 * 
 * Veja que para qualquer critério de ordenamento, basta alterar
 * esta função de comparação, mantendo a função de ordenamento intacta
 * */
int compara(int n1, int n2)
{
    int p1, p2;

    p1 = n1 % 2;
    p2 = n2 % 2;
    /* Guardando em duas varíaveis para fazer uma vez só esta 
     * divisão (para obter o resto)
     * */

    if ((p1 == 0) && (p2 == 0)){ //ambos pares
        return (n1 - n2);
        /* Se iguais vai retornar 0.
         * Se n1 maior, retornará um número positivo
         * */
	}

	/* aqui nem preciso me preocupar com números positivos ou 
	 * negativos. Basta ver se são pares ou não.
	 * */
    if ((p1) && (p2)){           // ambos impares
        return (n2 - n1);
	}
	
    if ((p1 == 0) && (p2)){		// n1 par, n2 impar
        return (-1);			// n1 menor (par sempre menor que impar pelo critério)
	}

	/* Se chegou até aqui sem encerrar é porque NECESSARIAMENTE n1 é IMPAR
	 * e n2 é PAR. n1 é, portanto, MAIOR. 
	 * */
    return (1);
}


/* Ordenamento pela técnica conhecida como select sort
 * Busca no vetor o menor de todos e coloca na posição [0]
 * continua para o menor de todos de [1] a [n-1] e assim
 * por diante. (menor == vem antes no ordenamento, não exatamente 
 * menor em grandeza numérica)
 */
int ordena(int v[], int n)
{
    int i, j, menor;

    for (i = 0; i < n; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
			/* if (v[j] < v[menor])   //  ordenamento original
			 * 		menor = j;
			 * */
            if (compara(v[j], v[menor]) < 0) {
                menor = j;      // novo menor eleito
            }
        }
        if (menor != i) { // só se precisa trocar
            j = v[menor]; // usando o j como temp para não definir mais uma var
            v[menor] = v[i];
            v[i] = j;
        }
    }
    return (i);
}
/* Ordenamento possui sempre duas partes: compara e troca.
 * Pegando qualquer algoritmo de ordenamento, basta identificar onde é a 
 * comparação e alterar a lógica só desta parte, mantendo todo o resto.
 * */
 
 
/* Somatorio de um numero também pode ser feito pela formula
 * matemática ((n*n) + n) /2.
 * 
 * Sem laço o que melhora MUITO o desempenho
 * Em 32 bits n*n não dá overflow até 40000
 * Acima disso teria que usar long int
 * 
 * AQUI SE GANHOU MUITO TEMPO DE DESEMPENHO
 * */
int somatorio(int n)
{
    if (n > 40000) {
        return (0);
    }
    return (((n * n) + n) / 2);
}

/* Uma função para imprimir o vetor, Para testes */
int impdebug(int v[], int n)
{
    int i;
    printf("# DEBUG. VETOR agora\n");
    for (i = 0; i < n; i++) {
        printf("# v[%5d] = %5d\n", i, v[i]);
    }
}

/* Preferi fazer uma função para ler inteiro */
int leint()
{
    int temp;

    while (scanf("%d", &temp) == 0) {
        printf("ERRO: ENTRADA INVALIDA.\n"); // MSG esperada pela ferramenta
        printf("# ERRO. Voce digitou lixo. Preciso de um numero\n");
        while (fgetc(stdin) != '\n');
    }
    return (temp);
}

int digita(int v[], int n)
{
    int i, num, resp;

    for (i = 0; i < n; i++) {
        printf("# Vet[%d] = \n", i);
        num = leint();
        resp = achou(v, i, num);
        if (resp >= 0) {
            printf("ERRO: %08d JA EXISTE.\n", num); // MSG esperada pela ferramenta
            printf("# INFO: %d já está em vet[%d]\n", num, resp);
            i--;
            continue;
        }
        v[i] = num;
    }
    return (i);
}

/* Uma função de teste só para verificar se o ordenamento está
 * correto. Removida a invocação depois de concluido e testado
 * o código
 * */
int verificaOrdena(int v[], int n)
{
    int i;

    // PARES
    n--;
    for (i = 0; i < n; i++) {
        if (v[i] % 2) {
            break;
            // Achou um IMPAR
        }
        if (v[i+1] % 2) {
			i++;
			break;
			/* v[i] é o último PAR. Próximo é IMPAR */
		}
        if (v[i] > v[i + 1]) {
            printf("# DEBUG: Erro ordenamento.\n");
            return (0);
        }
    }
    for (; i < n; i++) {
        if (v[i] < v[i + 1]) {
            printf("# DEBUG: Erro ordenamento.\n");
            return (0);
        }
    }
    printf("# DEBUG: Ordenado com sucesso\n");
    return (1);
}


/* Como coloquei na dica, pode ser usado algoritmo de MDC
 * (Máximo Divisor comum) para verificar se são primos 
 * relativos. Se MDC(x, k)== 1, então x e k são primos relativos.
 * 
 * Pode parecer mais lento procurar o maior divisor, quando que
 * basta achar um para saber que não são primos relativos.
 * 
 * Se for fazer com for, realmente é mais lento.
 * 
 * Porém para calcular o MDC existe o algoritmo de Euclides,
 * muito, mas MUITO, MASSSSSS MUUUUIIIITOOOOO mais rápido
 * que indo no for
 * */
int mdceuc(int n1, int n2)
{
    if (n2 == 0)
        return (n1);

    return (mdceuc(n2, n1 % n2));
}

int main()
{
    int n, i;
    int vet[VTAM];
    int n1, n2, t;

    do {
        printf("# Quantos elementos você quer (1 a %d)\n", VTAM);
        n = leint();
        if ((n <= 0) || (n > VTAM)) {
            printf("ERRO: TAMANHO INVALIDO.\n");
        }
    } while ((n <= 0) || (n > VTAM));

    digita(vet, n);
    //impdebug(vet, n);

    ordena(vet, n);

    //verificaOrdena(vet, n);
    //impdebug(vet, n);

    for (i = 0; i < n; i++) {
        n1 = vet[i];
        if (n1 < 0)
            n1 = ~n1 + 1;       // transformando em positivo modo hacker
        t = somatorio(n1);
        if (t < 0) {
            printf("ERRO: somatorio.\n");
        } else {
            printf("SOMATORIO DE %5d = %10d\n", vet[i], t);
        }
    }

    for (i = 0; i < n; i++) {
        n1 = vet[i];
        n2 = vet[(i + 1) % n];
        
        if (n1 < 0) {
            n1 = ~n1 + 1;
        }
        if (n2 < 0) {
            n2 = ~n2 + 1;
        }
        if (mdceuc(n1, n2) == 1) {
            printf("%d e %d: PRIMOS RELATIVOS\n", vet[i], vet[(i + 1) % n]);
        } else {
            printf("# NAO SAO PRIMOS RELATIVOS %d e %d (DIVISOR %d)\n", vet[i], vet[(i + 1) % n], mdceuc(n1, n2));
        }
    }
}
/* Os últimos testes exigiam bom desempenho. Esta solução NÃO TEM um ótimo 
 * desempenho (ordena é muito lenta) mas já foi suficiente para passar nos
 * testes. As otimizações aqui que fizeram ser rápido foram:
 * 
 * 1) cálculo do primo relativo através do MDC Euclides
 * 2) cálculo do somatório por fórmula e não por laço.
 * 
 * No teste 8 passou com 6s de execução (o limite era 10 segundos)
 * No teste 9 passou com 45s de execução (o limite era 50 segundos)
 *     (Sim, eu fiz esta resposta antes, vi que levava 45 segundos e configurei
 *      o teste 9 para 5 segundos a mais. :-D )
 * 
 * Com uma otimização na função de ordenamento (aguarde estruturas de 
 * dados II) o tempo do teste 9 baixou para 12s
 * */
 
