#include<stdio.h>
int main()
{
	int sum=0,i=0,sum1=0,size=11;
	int arr[11]={6,7,8,9,10,11,13,14,15,16,17};
	while(i<=11)
	{
		sum=sum+arr[i];
		i++;
	}
	printf("%d\n",sum);
	int ori=size*(size+1);
	int ori_=ori/2;
	printf("%d\n",ori_);
	int result=ori_-sum;
	printf("The missing element is:%d",result);
        return 0;
}

