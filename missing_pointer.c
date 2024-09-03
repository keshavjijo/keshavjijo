#include<stdio.h>
int main()
{
	int a[5]={10,11,13,15,16};
	int *pa=NULL,i=0;
	pa=a;
	printf("the missing number are:\n");
	int x=a[0];
	while(pa<=&a[4])
	{
		if(*pa-i !=x){
			printf("%d\n",*pa-1);
			x=x+1;
		}
		i++;
		pa++;
	}
	return 0;
}
