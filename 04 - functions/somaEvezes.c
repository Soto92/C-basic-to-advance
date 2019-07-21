#include <stdio.h>

int soma (int a, int b)
{
	int s;
	static int vezes=0;
	
	vezes++;
	
	printf("Ja fui chamado %d vezes\n", vezes);
	
	s = a+b;
	return(s);
}

int main()
{
	
	soma(10,20);
	
	soma(30,40);
	soma(30,40);
	soma(30,40);
	soma(30,40);
}
