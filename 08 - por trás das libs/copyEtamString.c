/* TITULO: Definição de "strings"
 * 
 * */

#include <stdio.h>
int strncpyES (char dst[], char ori[], int max)
{
	/* Copia ori para dst, respeitando max. 
	 * Retorna quantidade de cars copiados
	 * (que é o tamanho de dst)
	 * */
	int i=0;
	
	for (i=0; ori[i]; i++){
		if (i==(max-1)) {
			break;
		}
		dst[i]=ori[i];
	}
	dst[i]=0;
	return(i); // tamanho de dst
}

int tamanhoV1(char s[])
{
	int i, tam;
	
	tam = 0;
	for (i=0; s[i] != 0; i++){
		tam++;
	}
	return(tam);
}

int tamanhoV2(char s[])
{
	int i;
	
	for (i=0; s[i] != 0; i++);
		
	return(i);
}

int tamanhoV3(char s[])
{
	int i;
	
	for (i=0; s[i]; i++);
		
	return(i);
}

int tamanhoV4(char s[])
{
	int i=0;
	
	while (s[i]) i++;
		
	return(i);
}
int main()
{
	char lixo[100];
	char lixo2[5];
	int t;
	
	// digite uma string
	fgets(lixo, 100, stdin);
	t = tamanhoV4(lixo);
	if (lixo[t-1]=='\n'){
		lixo[t-1]=0;
	}
	
	printf("Voce digitou \"%s\"\n", lixo);
	
	printf("V1 tamanho: %d\n", tamanhoV1(lixo));
	printf("V2 tamanho: %d\n", tamanhoV2(lixo));
	printf("V3 tamanho: %d\n", tamanhoV3(lixo));
	printf("V4 tamanho: %d\n", tamanhoV4(lixo));
	
	strncpyES(lixo2, lixo, 5);
	printf("Copiado ficou \"%s\"\n", lixo2);
}
