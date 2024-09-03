#include <stdio.h>

int main() 
{
	int a[10]={3,6,8,8,10,12,15,15,15,20};
	int *p1,*p2;
        printf("The duplicate elements:\n");
	p1=a;
        while (p1<a+9){
               		p2=p1+1;
        	while (p2<a+10){
            			if (*p1==*p2){
               			printf("%d\n",*p1);
                		break;
            }
            p2++;
        }
        p1++;
    }

    return 0;
}

	

