#include <stdio.h>
#include <stdlib.h>

void move_step(int p1,int p2)
{
	printf("%c��%c\n",p1,p2);
} 

void hanoi(int num,char one,char two,char three)
{
	if(num==1)
	{
		move_step(one,three);
	}
	
	if(num>1)
	{
		hanoi(num-1,one,three,two);
		move_step(one,three);
		hanoi(num-1,two,one,three); 
	}
}

int main() 
{
	int num;
	char one,two,three;
	printf("��������Ҫ��ʼ��������Ϊ��\n");
	scanf("%d",&num);
	printf("����Ҫ���������������������\n");
	getchar();                                         /*������һ�ж���Ļس������ǳ���Ҫ��*/
	scanf("%c%c%c",&one,&two,&three); 
	printf("�ƶ�����Ϊ��\n");
	hanoi(num,one,two,three);
	return 0;
}
