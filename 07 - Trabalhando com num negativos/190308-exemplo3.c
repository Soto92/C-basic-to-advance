#include <stdio.h>
#define TAM 400000

/* leia n inteiros (nao mais que 400)
 * ate que seja lido um número negativo.
 * */
int main()
{
	int i, num;
	int v[TAM];
	int flag;
	
	
	flag = 1;
/*	for (i=0; i< TAM; i++){
		if (flag){
			scanf("%d", &num);
		}
		if (num < 0){
			flag = 0;
		}
		if (flag==1){
			v[i]=num;
		}
	} */
	
	for (i=0; i<TAM; i++){
		scanf("%d", &num);
		if (num<0){
			break;
		}
		v[i]=num;
	}
	flag = 0; 
}
