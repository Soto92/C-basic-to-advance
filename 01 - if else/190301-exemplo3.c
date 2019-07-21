#include <stdio.h>

int maior1 (int a, int b)
{
	int m;
	
	if (a>b){
		m = a;
	} else {
		if (a<b){
			m = b;
		} else {
			if (a==b){
				m = a;
			}
		}
	}
	return(m);
}
int maior2 (int a, int b)
{
	if (a>b)
		return(a);
		
	return(b);
}
int maior3( int a, int b)
{
	return(a>b?a:b); //ternário, outra maneira do If else..
}
