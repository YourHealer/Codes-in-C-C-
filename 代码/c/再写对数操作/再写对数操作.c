#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;
	scanf("%d",&num);
	int x=num;
	int n;
	for(n=0;x>0;n++)
	{
		x=x/10;
	}
	printf("%d\n",n);        /*ͨ������ȡ���ķ�ʽ���*/
	
/*	int k;
	n=1;x=num;
	while(x>=pow(10,n))
	{
		n++;
	} 
	printf("%d",n);         ͨ����10�Ĵη����Ƚ����*/
	
	int value[5];
	int i=0;
	x=num;
	
	for(i;i<n;i++)
	{
		value[i]=x%10;
		x/=10;
	}
	
	printf("�ӵ�λ����λ��ֵΪ��\n"); 
	 for(i=0;i<n;i++)
	 {
	 	printf("%d\n",value[i]);                /*���λ����ֵ*/ 
	 }
	 
	 printf("��������ת��Ľ��Ϊ��\n");
	 for(i=0;i<n;i++)
	 {
	 	printf("%d",value[i]);
	 }                                          /*��������ת*/ 
	 printf("\n");
	return 0;
}


