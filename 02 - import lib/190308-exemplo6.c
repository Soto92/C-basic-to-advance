#include <stdio.h>
#define TAM 400000

int main()
{
	int a;
	
	a = 40;
	
#include "lixo.c" //exemplo de como importar uma biblioteca feita por vc mesmo..
	
	printf("Valor do a = %d\n", a);
}
