#include <stdio.h>
#include <stdlib.h>
#define capacity 50                 /*ͨ���ı�capacity��ֵȷ����ͬ����Ϸ������Ӧ�Ĳ�ͬ���*/

void who_is_winner(int *pointer);

int main() 
{
	int people[capacity];

    who_is_winner(people); 
	
	return 0;
}

void who_is_winner(int *pointer)
{
	
	int index;
	int flag=0;
	int counter=capacity;
	
	for(index=0;index<capacity;index++)
	{
		*(pointer+index)=1;                 /*�����˸�ֵΪ1��������Ȧ��Ƿ������ˡ�*/ 
	}
	
	for(index=0;;index++)
	{
		if(index==capacity)
		{
			index=0;
		}
		
		    if(*(pointer+index)==1)
		    {
			    flag++;
		    }
		    else continue;
		
		        if(flag%3==0)
		        {
			        *(pointer+index)=0;
			        counter--;
		        }
		
		if(counter==1) break;

	}
	
	for(index=0;index<capacity;index++)
	{
		if(*(pointer+index)==1)
		{
			printf("�������������%d",index+1);
		}
	}
}
