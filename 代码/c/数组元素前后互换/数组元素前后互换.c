#include <stdio.h>
#include <stdlib.h>
#define amount 20

void swap(int* pointer1,int* pointer2,int n,int m);

int main() 
{
	int m,n;
	int number_1[amount];
	int number_2[amount];
	int index;
	
	printf("��������������������λ����\n");
	scanf("%d%d",&n,&m);
	
	if(n>amount)
	{
		printf("���޸�amount��ֵ��\n");
	}
	
	else
	{
		printf("����������Ԫ�أ�\n");
	for(index=0;index<n;index++) 
	{
		scanf("%d",&number_1[index]);
	}
	
	swap(number_1,number_2,n,m);
	
	for(index=0;index<n;index++) 
	{
		printf("%d ",number_2[index]);
	}
	
	printf("\n");
	}
	

	return 0;
}

void swap(int* pointer1,int* pointer2,int n,int m)
{
	int index;
	
		for(index=0;index<n;index++)
	{
		if(index<n-m)
		{
			*(pointer2+index+m)=*(pointer1+index);
		}
		else 
		{
		    *(pointer2+index+m-n)=*(pointer1+index);
		}
	}
}
















