#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define Li 20
#define Co 4
//MAURICIO ANDRÉS SOTO PEZOA
int main(){
	int mat[Li][Co],i,j,vetC[Co],vetL[Li],vetx[Li],soma=0,somaAux=0,menor=0,maior=0,mais=0,menos=0,maior2=0,mais2=0;	
	printf("Bem vindo a BURGUER LORD\n");
	printf("Faca seu pedido: \n1=SandubaDeLuz 2=JarjarBurguer 3=SkywalkerBurguer 4=BauruYoda:\n");
	 	 //laços para definir valores às posições da matriz
	for(i=0;i<Li;i++)	{
		printf("Pedido %i \n",i+1);
		for(j=0;j<Co;j++)	{
		printf("quant. do lanche %i:",j+1);
		mat[i][j]=rand()%4;		//random, valores aleatorios
		printf("%i\n",mat[i][j]);
		soma=soma+mat[i][j]; //soma total da matriz(lanches)	
		}
	}
	
	for(j=0;j<Co;j++){ //soma das colunas, usado um vetor (vetC)
		somaAux=0;
		for(i=0;i<Li;i++){
		somaAux=somaAux+mat[i][j];
		}
		vetC[j]=somaAux;		
	}

	for(i=0;i<Co;i++){ //laço para ver qual a posição maior do vetor (sabor mais vendido)
		if(i==0){
	  	maior=vetC[i];menor=vetC[i];
	  }
		if(vetC[i]>maior){
			maior=vetC[i];
			mais=i; // variavel"mais" para selecionar o indice do vetor(sabor mais vendido)
		}
		else{
        if(vetC[i]<menor){
            menor=vetC[i];
            menos=i;		//variavel menos para selecionar o indicecdo vetor (sabor menos vendido)
       	 }
      	}	
	}
	
	for(i=0;i<Li;i++){ //soma das linhas, usado um vetor (vetL)
		somaAux=0;
		for(j=0;j<Co;j++){
		somaAux=somaAux+mat[i][j];
		}
		vetL[i]=somaAux;
	}
	for(i=0;i<Li;i++){ //qual pedido pediu mais lanches
		if(vetL[i]>maior2){
			maior2=vetL[i];
			mais2=i; 
		}	
	}
	
	for(i=0;i<Li;i++)	{ //laço seleciona a linha (pedido)
		somaAux=0;
		for(j=0;j<Co;j++)	{ //este retoma a coluna (sabor)
		if(j==0){				//os if são para acrescentar valores aos pedidos
			somaAux=somaAux+15*mat[i][j];
		}
		if(j==1){
			somaAux=somaAux+28*mat[i][j];
		}
		if(j==2){
			somaAux=somaAux+30*mat[i][j];
		}
		if(j==3){
			somaAux=somaAux+25*mat[i][j];
		}
	        vetx[i]=somaAux;	//e no final os valores vão à posição do vetor X.
		}
	}
	somaAux=0; //soma total das posições do vetx, para saber o total dos pedidos.
	for(i=0;i<Li;i++){
		somaAux=somaAux+vetx[i];
	}
	
	printf ("\nTotal de lanches vendidos=%i\n",soma);
	printf("sabor mais vendido: %i \n e o menos vendido: %i\n",mais+1,menos+1);
	printf("Pedido %i pediu mais lanches que todos\n",mais2+1);
		for(i=0;i<Li;i++){
		printf("valor do pedido %i:%.2i reais\n",i+1,vetx[i]);
	}
	printf ("Total dos pedidos=%.2i reais\n",somaAux);

}
