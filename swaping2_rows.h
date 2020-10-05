#include<stdio.h>
void swaping2_rows(float m[20][20], int r1, int length_of_row, int r2) 
{
	int i;
	for (i=1; i<=length_of_row; i++)
	 {
		float temp;
		temp = m[r2][i];
		m[r2][i] = m[r1][i];
		m[r1][i] = temp;
	}
}
