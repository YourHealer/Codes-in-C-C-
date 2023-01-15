#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack> 
using namespace std; 

int n;									//����ʯͷ����
long long arr[200010]; 					//����߶�����
stack <long long> hei; 
 
int main() 
{
	while(~scanf("%d",&n))
	{
		bool flag=true;
		long long max=0;				//��ʼ�����ֵ 
		memset(arr,0,sizeof(arr));		//��ʼ������ 
		while(!hei.empty())
		{
			hei.pop();					//���ջ	
		} 
		
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			if(arr[i]>max)	max=arr[i];

		}
		
		for(int i=0;i<n;i++)
		{
			if(hei.empty())
			{
				hei.push(arr[i]);
			}
			else
			{
				if(arr[i]==hei.top()) hei.pop();
				else if(arr[i]<hei.top()) hei.push(arr[i]);
					 else 
					 {
					 	flag=false;
					 }
			}
		}	
		
		if(flag)
		{
			
			if(hei.size()==0)
			{
				printf("YES\n");
			}
			else if((hei.size()==1)&&(hei.top()==max))
			{
				printf("YES\n");
			}
				else
				{
					printf("NO\n");
				}
		}
		else printf("NO\n");
		
	}
	return 0;
}
