#include <stdio.h>
#include <stdlib.h>

int main() 
{
	float average(float array[],int people);
	int i;
	float grade[100];
	int people;
	printf("�����ж����ˣ�\n");
	scanf("%d",&people);
	printf("������ɼ���\n");
	for(i=0;i<people;i++)
	{
		scanf("%f",&grade[i]);
	}
	
	float jacket;
	jacket=average(grade,people);
	printf("%f",jacket);
	return 0;
}


float average(float array[],int people)
{
	float sum=0;
	int i;
	for(i=0;i<people;i++)
	{
		sum=sum+array[i];
	}
	
	float result;
	result=sum/people;
	return(result);
	
 } 

