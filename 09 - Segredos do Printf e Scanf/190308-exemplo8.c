#include <stdio.h>


int main()
{
	int ret;
	int n;
	
	
	printf("Digite numeros. Encerre com negativo\n");
	
	while (1){
		if (scanf("%d", &n)!=1){      //verifica se é letra, numero sempre retorna 1 quando %d ou %i...
			printf("Qual parte de digitar um numero tu nao entendeu?\n");
			while(getchar()!='\n'); // mini fflush do professor Elgio. (fflush em alguns casos é prejudicial..)
			continue;
		}
		if (n<0){
			break;
		}
		printf("Digitou %d\n", n);
	}
	printf("FIM\n");
}
