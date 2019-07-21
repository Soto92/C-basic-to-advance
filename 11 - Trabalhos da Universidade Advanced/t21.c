#include <stdio.h>
#include <stdlib.h>

/*
	Essa função retorna 1 caso a string passada como parametro seja um numero, ou 0
	caso não seja um numero.
*/
int ehNumero(char str[])
{
	int i;
	for(i=0; str[i] != '\0'; i++)
	{
		if(i == 0 && (str[i] == '+' || str[i] == '-')) continue; // o primeiro caracter pode ser um sinal de + ou -
		else if(!(str[i] >= 48 && str[i] <= 57)) return 0; // caso seja um caracter invalido, retorna erro
	}

	return 1; // se chegou aqui é porq nao retornou 0 indicando erro, logo retorna 1 de sucesso
}

/*
	Essa função retorna quantos dos parametros são numeros
*/
int nNumeros(int n,char **numeros)
{
	int i, contador = 0;
	for(i=1;i<n;i++)
	{
		if(ehNumero(numeros[i])) contador++;
	}
	return contador;
}

int main(int argc, char *argv[])
{
	if(argc < 3) {
		printf("ERRO.\n");
		printf("# Erro. Voce precisa passar dois ou mais numeros.\n");
	}else {

		int maior, menor, soma = 0, i, qtdNumeros, qtdSomada = 0, numero;
		qtdNumeros = nNumeros(argc, argv);

		for(i=1;i<argc;i++)
		{
			if( ehNumero(argv[i]))
			{
				numero = atoi(argv[i]);
				if(qtdSomada == 0)
				{
					maior = numero;
					menor = numero;
					soma += numero;
					qtdSomada++;
				}else 
				{
					if(maior < numero) maior = numero;
					if(menor > numero) menor = numero;
					soma += atoi(argv[i]);
					qtdSomada++;
				}
			}else printf("# ATENCAO: \"%s\" nao eh um numero.\n", argv[i]);
		}

		if(qtdNumeros >= 2)
		{
			printf("%d %d %d\n",soma,maior,menor);
		
		}else printf("# Os %d parametros do main nao tem 2 ou mais numeros.\n",argc-1);
	}

	printf("# FIM\n");

	return 0;
}
