#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;
	float amount=0;
	float total,average;
	int i;
	for(i=0;total<100000;i++) 
	{
		printf("���޽����������������һ�ξ������Ǳ����������õ���ů�����ľ����ֵΪ��\n");
		scanf("%f",&amount);
		total=total+amount;
	}
	num=i;
	average=total/num;
	printf("\n�������紮����\n�������þ���ܶ�Ϊ��%.2f.\n��������%d��\n�˾�����Ϊ��%.2f��\n",total,num,average);
	return 0;
}
