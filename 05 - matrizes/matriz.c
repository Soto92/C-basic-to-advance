/* TITULO: Definição de uma matriz
 * 
 * */

#include <stdio.h>

#define MAXLINHAS 100
#define MAXCOL    100

int zeramatriz(int m[][MAXCOL], int l, int c)
{
	int i, j;
	
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
			m[i][j] = 0;
		}
	}
}

int main()
{
	int m[MAXLINHAS][MAXCOL];

	zeramatriz(m, 10, 20);
}
