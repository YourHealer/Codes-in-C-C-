#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int num;
	int x;
	scanf("%d",&num);
	x=num;
	int n=0;
	for(n;x>0;n++)
	{
		x/=10;
	}
	printf("������%dλ��.\n",n);      /*��λ��*/ 
	
	x=num;
	int fly[5];
	int i=0;
	printf("�����ӵ�λ����λΪ��\n"); 
	for(;num>0;i++)
	{
	fly[i]=num%10;
	printf("%d\n",fly[i]);            /*���λ����ֵ*/ 
	num=num/10;	
	}
	
	printf("������Ϊ��");
	for(i=0;i<n;i++)
	{
	printf("%d",fly[i]);	/*������*/ 
	}
	printf("\n");
	
}
