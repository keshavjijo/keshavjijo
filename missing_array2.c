#include<stdio.h>
int main()
{
        int a[11]={1,2,3,4,5,6,9,10,12,13,14};
        int i=0,x,y,c=0;
        printf("missing element:\n");
        while(i<10)
        {
                x=a[i]+1;
                i++;
                y=a[i];
                if(x!=y)
                {
                        int d=y-x;
                        while(d>c)
                        {
                                printf("%d\n",a[i]-d);
                                d--;
                        }
                }
        }
        return 0;
}
