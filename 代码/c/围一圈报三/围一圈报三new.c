#include <stdio.h>
#include <stdlib.h>
//������Ϸ������ 
#define total 50 

void check(int* pointer);

int main() 
{
	int index; 
	int circle[total];
	check(circle);
	
	for(index=0;index<total;index++)
	{
		if(*(circle+index)==1)
		{
			printf("%d",index+1);
		}
	}
	
	return 0;
}

void check(int* pointer)
{
	int counter=total;
	int index; 
	int flag=0;
	for(index=0;index<total;index++)
	{
		//�ٶ�һ��ʼ�����˶���Ȧ���Ϊ1 
		*(pointer+index)=1;
	}
	
	for(index=0;;index++)
	{
		if(index==total)
		{
			index=0;
		}
	
	if(*(pointer+index)==1)
	{
		flag++;
	}
	else 
	{
		continue;
	}
	
	if(flag%3==0)
	{
		*(pointer+index)=0;
		counter--;
	 } 
	 
	 if(counter==1)
	 {
	 	return;
	 }
	}
	
} 
