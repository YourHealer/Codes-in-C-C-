#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	int j;
	
	for(i=2;i<=100;i++)
	{
	    int flag=1;      /*��־����Ӧ����ÿ�����ѭ����ʼ��ʱ�����Ϊ1�����ڲ�ѭ���ж��Ƿ�Ϊ0����������㶨�岢��ʼ����־����*/
		for(j=2;j<=(i-1);j++)
		{
			if(i%j==0)
			{
				flag=0;
			}
			
		}
		    if(flag==1)
			{
				printf("%d\t",i);
			}
		
	}
	 
	return 0;
}
