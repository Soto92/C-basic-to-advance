#include <stdio.h>

int main()
{
	int a, b, c;
	
	a = 20;
	c = 10;
	b = 200;
	
	if ((a>c) && (b = 5)){    
		printf("OK\n");     // isto printa OK, por quê? porque no if faltou um '=', ou seja (b == 5) se true printa ok, se falso sai do if
	}
	
	printf("Valor de b = %d\n", b); 
	
	return(0);
}
