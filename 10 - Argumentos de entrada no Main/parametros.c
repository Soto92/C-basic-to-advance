#include <stdio.h>

int tamanho(char s[])
{
	int i;
	
	for (i=0; s[i];i++);
	return(i);
}

int main(int npar, char *pars[]) //Exemplo de main que recebe parametros
{
	int i;
	
	printf ("Recebi %d parametros\n", npar);
	for (i=1; i<npar; i++){
		printf("[%d] %d cars = %s\n", i, tamanho(pars[i]));
	}
		
	return(0);
}
	
