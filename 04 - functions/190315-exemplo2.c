#include <stdio.h>


int calc(int n)    //function feita de maneira avançada para calculo de somatorio.
{
	if (n<=0){
		return(0);
	}
	
	return(n + calc(n-1));
}

int main()
{
	int a, n;
	
	printf("# Digite um numero:\n");
	if (scanf("%i", &a)==0){
		printf("# DIGITOU LIXO. ENCERRADO.\n");
		return(0);
	}
	
	n = calc(a);
	printf("# Somatorio de %-5d = %05d\n", a, n);
	
}
