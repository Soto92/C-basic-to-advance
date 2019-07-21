#include <stdio.h>

int main()
{
	int a;
	//a = a * -1;     

	printf ("informe o numero a ser negativo: \n");
	scanf ("%i", & a);
	a = ~a + 1;         //maneira alternativa de deixar seu numero negativo
	printf ("%i \n",a); 
}
