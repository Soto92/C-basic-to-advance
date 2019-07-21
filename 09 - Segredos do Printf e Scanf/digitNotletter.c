#include <stdio.h>

int main()
{
	int num;
	
	printf("Digite numero: \n");
	if (scanf("%d", &num)==0){
		printf("ERRO. Digitou lixo\n");
		return(1);
	}
	
	printf("OK\n");
	return(0);
}
