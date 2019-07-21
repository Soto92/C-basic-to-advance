#include <stdio.h>
#define TAM 400000

/* leia n inteiros (não mais que 400)
 * se for positivo diga se e par ou impar
 * * */
int main()
{
	int i, soma;
	int v[TAM];
	
	
	for (i=0; i< TAM; i++){
		scanf("%d", &v[i]);
		if (v[i]>0){
			if ((v[i] % 2)==0){
				printf("PAR\n");
			} else {
				printf("IMPAR\n");
			}
		}
	}
	
	for (i=0; i< TAM; i++){
		scanf("%d", &v[i]);
		if (v[i]<0){
			continue;
		}
		
		if (v[i]&1){
			printf("IMPAR\n");
		} else {
			printf("PAR\n");
		}
		
	}
}
