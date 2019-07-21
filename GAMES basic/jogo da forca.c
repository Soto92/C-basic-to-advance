#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
//Mauricio Andrés Soto Pezoa
// Jogo da forca
int main(){
char str[10][11]={
"SISTEMA", "RAIZES", "BOSQUE", "CAMPO", 
"CANSADO","COLINA","ASFALTO","FILHOTE","CARRO","BOBINA"}; //banco de palavras, de 0 a 9;

char temp[11],abc;
int i=0,j=0,errou=0,encontrada=0,x=0,k=0,tam=0;
puts("JOGO DA FORCA\n");
	srand(time(NULL));
	x=rand()%10;			//randomica modo de selecionar o indice da linha da matriz(0 a 9); apos selecionar um numero aleatorio, o atribui à variavel x, logo seleciona a palvra da linha X(numero 3 por exemplo);
	tam=strlen(str[x]);			//tamanho da palavra da linha x;
	printf("A palavra tem: %i letras\n",tam);
	//puts(str[x]);				//mostra a palavra, para testes;
	for(i=0;i<tam;i++){
		temp[i]='*';		//variavel char temp, recebe os * e o tamanho da palavra selecionada da matriz;
	}puts(temp);

	while(j>=0){	
	printf("\nDigite uma letra:\n");
	abc=getchar();
	fflush(stdin);
	if((abc>='a')&&(abc<='z')||(abc>='A')&&(abc<='Z')){ 	//verifica se é uma letra do alfabeto;
		abc=toupper(abc);
			for(k=0;k<tam;k++){
				if(abc==temp[k]){			//verifica se a letra já está contida em temp, caso sim é repetida
				puts("\nLetra repetida!");
				}
				else if(abc==str[x][k]){		//compara se a letra é igual as da palavra selecionada.
				puts("\nLetra encontrada!");
				temp[k]=abc;
				encontrada++;
				}	else{
				errou++;
				}	
			} 	puts(temp);	//imprime os * com  as letras encontradas.
			
		if(errou==tam){
		j++;
		printf("\nLetra errada! restam %i chances\n",10-j);
		}
			errou=0;
		}else{
		puts("\nCaractere invalido, escolha letra de A a Z!");	
		}
		if(encontrada==tam){
		puts("\nParabens vc acertou a palavra!");
		break;
		}
		if(j==10){										//se atingir j=10 é encerrado o jogo, perdeu.
		puts("Lamento mas desta vez vc perdeu o jogo,\n a palavra era: ");
		puts(str[x]);
		break;			
		}
	}	
}
