#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char passage[3][20];
	
	int i,j;
	
	int counter_big=0;
	int counter_small=0;
	int counter_num=0;
	int counter_space=0;
	int counter_other=0;
	
	printf("�������ַ���\n"); 
	for(i=0;i<3;i++) 
	{
	    gets(passage[i]);
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<20;j++)
		{
			if((passage[i][j]>'A')&&(passage[i][j]<'Z'))
			{
				counter_big++;
			}
			
			else if((passage[i][j]>'a')&&(passage[i][j]<'z'))
			     {
				 counter_small++;
			     }
			
			     else if((passage[i][j]>'0')&&(passage[i][j]<'9'))
			     {
				 counter_num++;
			     }
			
			          else if(passage[i][j]==' ')
			          {
			 	      counter_space++;
			          }
			          
			               else 
						   {
						   	counter_other++;
						   }
		}
	}
	printf("��д��ĸ��Ϊ��%d��Сд��ĸ��Ϊ��%d��������Ϊ��%d���ո���Ϊ��%d�������ַ���Ϊ��%d��\n",counter_big,counter_small,counter_num,counter_space,counter_other);
	return 0;
}
