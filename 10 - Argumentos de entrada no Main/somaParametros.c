#include <stdio.h>
#include <stdlib.h>

int tamanho(char s[])
{
	int i;
	
	for (i=0; s[i];i++);
	return(i);
}

/* Mais comum, mas não necessário:
int main(int argc, char *argv[])
* */

int main(int npar, char *pars[])
{
	int i;
	int n1, n2;
	
	if (npar != 3){
		printf("Uso inadequado. Preciso de dois numeros\n");
		return(1);
	}
	
	
	printf ("Recebi %d parametros\n", npar);
	
	/* soma de pars[1] com pars[2] */
	n1 = atoi(pars[1]);
	n2 = atoi(pars[2]);
	
	for (i=1; i<npar; i++){
		printf("[%d] %d cars = %s\n", i, tamanho(pars[i]),pars[i]);
	}
	
	printf("Soma = %d\n", n1+n2);	
	return(0);
}
