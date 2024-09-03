#include<stdio.h>
int main()
{
        int a[10]={3,6,8,8,10,12,15,15,15,20};
        int i=0,j;
        printf("the duplicate element:");
        while(i<9){
                j=i+1;
                while(j<10){
                        if(a[i]==a[j]){
                                printf("%d\n",a[j]);
                                break;
                        }
                        j++;
                }
                i++;
                }
                return 0;
}

