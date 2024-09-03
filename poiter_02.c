#include<stdio.h>
int main()
{
        int a[7]={22,33,44,55,66,77,88};
	int *pa=a;
        while(pa<&a[5]){
                        printf("%d\n",*pa);
                        pa++;
	}
       return 0;
}


