#include <stdio.h>
#define TAM 4
// verifico quantos valores sao negativos, duas maneiras:
int main()
{
	int i, conta;
	int v[TAM];

	v[0]=-3;
	v[1]=0;
	v[2]=-34;
	v[3]=-34;
	
	conta = 0;
	for (i=0; i<TAM; i++){
		if (v[i]<0){
			conta = conta + 1;
		}
	}
	printf ("%i\n",conta);
	

//agora o nivel avançado: 
	conta = 0;
	for (i=0; i<TAM; i++){
		conta = conta + (v[i]<0); 
	}
	printf ("%i\n",conta);
	
}
