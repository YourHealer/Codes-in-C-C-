#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i;
	int j;
    int add;
	for(i=2;i<=1000;i++)
	{   
	    add=0;                               /*Ҫ��֤��ÿ�������жϿ�ʼʱ��addӦ�ù���0.��˲���int add=0�����ˣ�Ӧ���ڴ˴�������ÿһ�μӷ�����ǰaddΪ0��������*/ 
		for(j=1;j<i;j++)
		{   
		    
			if(i%j==0)
			{
			add=add+j;
			}
				
		}
		if(i==add)
		{
			printf("%d\n",i);
		}
		
	} 
	return 0;
}
