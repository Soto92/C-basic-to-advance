#include <stdio.h>

int main()
{
	int a, b, c;
	
	a = 30;
	b = -31;
	if (a+b){
		printf("SIM somou\n");
	} else {
		printf("NAO somou\n");
	}
	
	a = 10;
	b = 20;
	if (a/b){
		printf("SIM div \n");
	} else {
		printf("NAO div\n");
	} 

	c = (a>b);   //retorna 0, falso
	printf("Valor de c = %d\n", c);
	
	c = (a<b);   //retorna 1, verdadeiro
	printf("Valor de c = %d\n", c);
	
}
