#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num[11]={0,3,6,9,12,15,18,21,24,27};
	int value;
	int mark;
	int i; 
	printf("�������������ǣ�\n");
	scanf("%d",&value); 
	for(i=0;i<10;i++)
	{
		if(value<num[i])
		{
			mark=i;                     /*��ǲ���λ��*/
			break;                      /*�����ɣ�����ѭ��*/ 
		}
	}
	for(i=10;i>mark;i--)
	{
		num[i]=num[i-1];                /*ͨ������λ�ƣ�ʵ�������벿��Ԫ�ذ���*/ 
	}
	num[i]=value;                       /*��������*/ 
	for(i=0;i<11;i++)
	{
		printf("%d\t",num[i]);
	}
	
	return 0;
}
