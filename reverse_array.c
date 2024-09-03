#include<stdio.h>
int main()
{

    int arr[5] = {1,2,3,4,5}; 
    int temp,i,j;
    printf("Original array:");
    {
        printf("%d",arr[i]);
    }
    while(i<=0,i--,j++);
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    printf("\nReversed array:");
    {
        printf("%d",arr[i]);
    }
    return 0;
}

