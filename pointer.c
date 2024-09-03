#include<stdio.h>
int main()
{
	int a=20;
	int *pa;
	pa=&a;
	printf("%p\n",&a);
	printf("%d",a);
	return 0;
}

