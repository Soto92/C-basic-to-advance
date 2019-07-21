#include <stdio.h>
// retorna chars entre aspas do printf

int main()
{
	int ret;
	int a;
	
	a = 500;
	
	ret = printf("Valor de a e = %i\n", a);
	
	printf("Ele me retornou %i chars\n", ret);
}
