#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a,int b)
{
	if(a>b)	
	{
		return b;
	}
	else return a;
} 

int main() 
{
	//������
	int result=0; 
	
	//������Ч���������� 
	int left;
	int right;
	
	//�������� 
	int n;
	
	//���崢�����Ŵ����ַ�����
	int record_left[100005];
	int record_right[100005];
	char c;
	
	//����ѭ������
	int i,j;
	
	//�������� 
	scanf("%d",&n);
	
	//�̵��س� 
	getchar(); 
	
	//�ж��Ƿ�Ϸ�
	int flag; 
	
	//��¼�Ϸ��ַ�����
	int record_middle=0; 
	
	//��ʼ������
	memset(record_left,0,sizeof(record_left));
	memset(record_right,0,sizeof(record_right));
	 
	for(i=0;i<n;i++)
	{
		//��ʼ����Ϊ�Ϸ� 
		flag=1;
		
		left=0;
		right=0;
		
		while((c=getchar())!='\n') 
		{
			if(c=='(')
			{
				left++;
			}
			else if(left!=0)
				{
				left--;
				}
				else
				{
					right++;
				}
		}
		
		//�ж��Ƿ�Ϸ�
		if((left>0)&&(right>0))
		{
			flag=0;
		} 
		
		//�жϺϷ��е���� 
		if(flag==1)
		{
			//�������� 
			if((left==0)&&(right==0))
			{
				record_middle++;
			}
		
			//���Ҵ�
			if((left>0)&&(right==0)) 
			{
				record_left[left]=record_left[left]+1;
			}
		
			//����
			if((left==0)&&(right>0))
			{
				record_right[right]=record_right[right]+1;
			} 
		}
		
		 
	}
	
	for(i=0;i<100000;i++)
	{
		//�Խ�������ۼ� 
		result=result+min(record_left[i],record_right[i]);
	}	

	//������ 
	printf("%d\n",result+record_middle/2);
	
	return 0;
}
