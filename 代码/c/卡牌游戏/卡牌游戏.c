#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

	//�������� 
	int n;
	
	//�������ƺ��ƶ����� 
	int hand[200010];
	int hea[200010];
	
	//����ѭ������ 
	int i;
		
	//�����־����
	int flag[200010]; 
	
	//�����־��������ʼ��Ϊ1������ 
	int mark=0;
	 
	//����1�ĳ�ʼλ�� 
	int signal=-1; 
	
	//�����ж����� 
	int judge[200010];
	
	//���峤�ȱ���
	int length; 
	
int main() 
{

	//��ʼ������
	memset(hand,0,sizeof(hand));
	memset(hea,0,sizeof(hea));
	memset(flag,0,sizeof(flag));
	memset(judge,0,sizeof(judge)); 
	

	//�������� 
	scanf("%d",&n);
	
	//�������� 
	for(i=0;i<n;i++)
	{
		scanf("%d",&hand[i]);
		getchar();
	}
	
	//�����ƶ� 
	for(i=0;i<n;i++)
	{
		scanf("%d",&hea[i]);
		getchar(); 
	}
	
	//�������� 
	for(i=0;i<n;i++)
	{
		if(hand[i])
		{
			flag[(hand[i])]=1;
			judge[(hand[i])]=flag[(hand[i])]-hand[i];
		} 
	}
	
	//�����ƶ� 
	for(i=0;i<n;i++)
	{
		if(hea[i])
		{
			flag[(hea[i])]=i+2;
			judge[(hea[i])]=flag[(hea[i])]-hea[i];
		} 

	}
	
	//�ж��ƶ����Ƿ���1������м���λ�� 
	for(i=0;i<n;i++)
	{
		if(hea[i]==1)
		{	
			//1�������� 
			mark=1;
			//��¼1��λ�� 
			signal=i;
			
			break;
		}
	}
		
	//����Ƚϴ�С���� 
	int max=0;
	
	//��Ѱ���ģ�������-������� 
	for(i=1;i<=n;i++)
	{
		if(judge[i]>judge[max])
		{
			max=i;
		}
	}
		
	//1������ 
	if(mark==0) 
	{
		int a=judge[max]+n;
		printf("%d\n",a);
	} 
	
	//1���ƶ�����Ӹ�λ�õ��Ƶ��Ƿ�Ϊ˳�� 
	else
	{
		int reminder=1; 
		for(i=n-1;i>=signal;i--)
		{
			//ͨ�������ж��ƶ�β�Ƿ����� 
			if(hea[i]!=(i-signal+1))
			{
				reminder=0;
			}
			
		}
		
		//�ƶ�β���� 
		if(reminder==1)
		{
			//����������� 
			length=n-signal;
			
			int healer=1;
			
			//�ж��ܷ�����
			for(i=0;i<n-length;i++)
			{
				//������ 
				if(hea[i]!=0)
				{
					if((judge[(hea[i])]+length)>0)
					{
					healer=0;
					}
				}
				
			
			} 
				if(healer)
				{
					int b=n-length;
					printf("%d\n",b);
				}	
				
				//������
				else
				{
					int c=n+signal+1;
					printf("%d\n",c);
				} 
		} 
		//�ƶ�β������ 
		else
		{
			int d=judge[max]+n;
			printf("%d\n",d);	
		 } 
	} 
	

	return 0;
}
