#include <stdio.h>
#include <stdlib.h>

#define MAXFRASE 1000
#define TAMFRASE 5000

// T16 resolucao

int ES_strlen (char s[])
{
	int i;
	for (i=0; s[i]; i++);
	return(i);
}


int troca (char frase[], char t1[], char t2[])
{
	static int ncars=0;
	
	int i, j;
	
	for (i=0; frase[i]; i++){
		/* para cada car de frase... */
		for (j=0; t1[j]; j++){
			/* para este car de frase, para cada car de t1 */
			if (frase[i] == t1[j]){
				/* se o car de frase for igual a este car de t1,
				 * troca o car de frase pelo car de t2 de mesma
				 * posição de t1
				 * */
				ncars++;
				frase[i] = t2[j];
				break;
				/* Sai fora para não haver duas trocas do mesmo caractere
				 * (tinha testes que pegavam isso. Exemplo de string de troca:
				 * ABab abAB
				 * quero inverter as letras AB de maiusculas para minusculas
				 * Se não tiver este break, vai trocar um 'a' por 'A' e
				 * depois trocar 'a' que foi recem trocado por 'A' novamente
				 * não fazendo na verdade troca alguma :-O
				 * */
			}
		}
	}
	return(ncars);
}

int main(int argc, char *argv[])
{
	char frases[MAXFRASE][TAMFRASE+1];
	int i, tam, qtd;
	int qtroca;

	if (argc != 4){
		printf("ERRO: PARAMETROS.\n");
		printf("\n# Voce deve passar a quantidade de frases e as duas strings de troca\n");
		return(1);
	}
	
	qtd = atoi(argv[1]);
	if ((qtd<=0) || (qtd>MAXFRASE)){
		printf("ERRO: %s INVALIDO.\n", argv[1]);
		printf("# Voce passou um valor (%s) inválido para quantidade de frases. Deve ser de 1 a %d\n", argv[1], MAXFRASE);
		return(2);
	}

	if (ES_strlen(argv[2]) != ES_strlen(argv[3])){
		printf("ERRO: TRANSFORMACAO.\n");
		printf("# [%s] e [%s] não tem a mesma quantidade de cars\n", argv[2], argv[3]);
		return(3);
	}
	printf("# Digite %d frases de ate %d cars cada\n", qtd, TAMFRASE);
	for (i=0; i<qtd; i++){
		fgets(frases[i], TAMFRASE, stdin);
		tam = ES_strlen(frases[i]);
		if (frases[i][tam-1]=='\n'){
			frases[i][--tam]=0;
		}
	}
	printf("# Digitados todas as %d frases\n", i);
	printf("# imprimindo elas transformadas [%s] <==> [%s]\n", argv[2], argv[3]);
	
	for (i=0; i<qtd; i++){
		printf ("\n#    [%d] = \"%s\"\n", i, frases[i]);
		qtroca = troca (frases[i], argv[2], argv[3]);
		printf ("FRASE[%d] = \"%s\"\n", i, frases[i]);
		printf ("# Ate agora %d cars trocados em todas as frases.\n", qtroca);
	}
	printf("%d\n", qtroca);
	printf("# %d cars trocados ao todo.\n# FIM\n", qtroca);
	return(0);
}
