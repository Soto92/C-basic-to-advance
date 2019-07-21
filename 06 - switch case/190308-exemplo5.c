#include <stdio.h>
#define TAM 400000
// switch case e default
int main()
{
	char op;

	op = 'B';
	switch (op){
		case 'A':
			printf("Digitou A\n");
			break;
		case 'B':
			printf("Digitou B\n");
			break;
		case 'C':
			printf("Digitou C\n");
			break;
		default:
			printf("Nao e nenhum\n");
		
	}
}
