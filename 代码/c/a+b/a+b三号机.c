#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j,k;
int main() 
{
	
//������������ 
	int amount;
	scanf("%d",&amount);
	
//������ά���� ��һά���ڶ�Ӧ�ڼ������� �ڶ�ά������������ 
//a��bΪ�ַ����� cΪ���������� 
	char a[100010];
	char b[100010];
	int c[100010];
	
// ����a�ĳ��� b�ĳ��� 
	int length_a,length_b;
//����c�ĳ��� 
	int counter=0;
	
//����������λ�ĺ����һλ�Ľ�ֵ�ĺ�
	int judge=0; 
//��ȷ�ĸ��ַ�������/��һЩ
	int min=0; 
	int max=0; 
	

//  ���������ַ���������	
	for(j=0;j<amount;j++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	//������ԭλ��ֵ
		int stay=0;
	//��������ֵ 	
		int leave=0;
		scanf("%s %s",a,b);
	

//��ʼ������c 
		memset(c,0,sizeof(c));
		
//���a��b�ĳ��� 
	length_a=strlen(a);
	length_b=strlen(b);
	
//ȷ��˭���� 
	if(length_a>length_b)
	{
		min=length_b;
		max=length_a;
	}
	else
	{
		min=length_a;
		max=length_b;
	}
	
//	������� 
	for(i=1;i<=max+1;i++)
	{
		//���벿�� 
		if(i<=min)
		{
			//�����Ӧλ�üӺ� 
			judge=(a[length_a-i]-48)+(b[length_b-i]-48)+leave;
			// ��λ��ֵ 
			leave=judge/2;
			// ���µ�ֵ 
			stay=judge%2;
			// c�Ķ�ӦλΪ���µ�ֵ 
			c[i-1]=stay;	
			counter++;	
		}
		//�����벿�� 
		if(i>min&&i<=max)
		{
			if(length_a>length_b)
			{
				judge=(a[length_a-i]-48)+0+leave;
				leave=judge/2;
				stay=judge%2;
				c[i-1]=stay;	
				counter++;
			}
			if(length_b>length_a)
			{
				judge=(b[length_b-i]-48)+0+leave;
				leave=judge/2;
				stay=judge%2;
				c[i-1]=stay;		
				counter++;
			}
		}
		
		//���ܵ���߽�λ 
		if(i==(max+1))
		{
			if(leave==1)
			{
				c[i-1]=leave;
				counter++;
			}
		}
	
	}
	

// ��ʽ��� 
	for(k=0;k<(counter-length_a+2);k++)
	{
		printf(" ");
	}
	printf("%s\n",a);
	
		printf("+");
		for(k=0;k<(counter-length_b+1);k++)
		{
			printf(" ");
		}
		printf("%s\n",b);
		
			for(k=0;k<(counter+2);k++)
			{
				printf("-");
			}
			printf("\n");
			
					for(k=0;k<2;k++)
				{
					printf(" ");
				}
				for(counter;counter>=1;counter--)
				{
					printf("%d",c[counter-1]);
				}
				printf("\n");
		
	}


	return 0;
}
