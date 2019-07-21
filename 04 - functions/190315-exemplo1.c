#include <stdio.h>


int fazalgo(int x, int y)
{
	x = 34;
	
	return(x+y);
}

int main()
{
	int a, b;
	
	a = 56;
	b = 67;
	fazalgo(a, b); //chamar função externa
	printf("Novo a = %d\n", a);
}
