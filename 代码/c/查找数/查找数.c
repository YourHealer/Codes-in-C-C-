#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num[15];
	int i;
	printf("��Ӵ�С����ʮ�������\n");
	for(i=0;i<15;i++) 
	{
		scanf("%d",&num[i]);
	}
	
	int value;
	printf("������������ҵ�����\n");
	scanf("%d",&value); 
	
	int position;
	int flag=0;
	for(i=0;i<15;i++)
	{
		if(value==num[i])
		{
			flag=1;
			position=i+1;
		}
	}
	
	if(flag==1)
	{
		printf("λ������ĵ�%d��λ�á�\n",position);
	}
	
	if(flag==0)
	{
		printf("�޴���\n"); 
	}
	return 0;
}
