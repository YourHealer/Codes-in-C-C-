#include <stdio.h>
#include <stdlib.h>
#define amount 3

int main() 
{
	int index;
	int jacket;
	int vote; 
	char call[20];
	struct Information
	{
		char name[20];
		int counter;
	};
	
	struct Information people[amount];
	
	for(index=0;index<amount;index++)
	{
		scanf("%s",people[index].name);
	}
	
	printf("�������������\n");
	scanf("%d",&vote);
	
	for(index=0;index<vote;index++)
	{
		scanf("%s",call);
		for(jacket=0;jacket<amount;jacket++)
		{
			if(strcmp(call,people[jacket].name)==0)
			{
				(people[jacket].counter)++;
			}
		}
	}
	
	printf("��Ʊ��Ϊ��\n");
	printf("%d,%d,%d",people[0].counter,people[1].counter,people[2].counter);
	return 0;
}
