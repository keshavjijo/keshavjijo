#include<stdio.h>
int main()
{
	int i,j,N,counter = 0;

while (i < N)
{
    int j = 0;
    while (j < N)
    {
         if (counter[i][j] < 10000)
         {
             counter[i][j] = (i, j, counter[i][j]);
         }
         j++;
    }
    i++;
}
