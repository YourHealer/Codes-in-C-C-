#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
//������������ 
int amount;
//���山����� 
long long int n;
//����ѭ������ 
long long int i;
long long int j; 
//������������λ�� 
long long int selected;
//�������� �����λ�õĸ߶�ֵ 
long long int height[100005];
//������������� 
long long int res; 
//�������׼ 
long long int standard_left;
//�����ұ�׼ 
long long int standard_right;


int main() 
{
	scanf("%d",&amount);
	
	for(j=0;j<amount;j++)
	{
		
//������	
	scanf("%lld",&n);
	
//��ʼ���������� 
	memset(height,0,sizeof(height)); 
	selected=0; 
	res=0;
	
//����ԭ����߶� 
	for(i=0;i<n;i++)
	{
		scanf("%lld",&height[i]);
		getchar();
	}
	
//����ߵ����� 
	for(i=0;i<n;i++)
	{
		if(height[selected]<height[i])
		{
			selected=i;
		}
	}
	
//��벿��ѭ�� 
	standard_left=height[0];
	for(i=0;i<selected;i++)
	{
		if(height[i]>standard_left)
		{
			standard_left=height[i];
		}
		if(height[i]<=standard_left)
		{
			res=res+standard_left-height[i];
		}
	}
	
//�Ұ벿��ѭ��
	 standard_right=height[n-1];
	for(i=n-1;i>selected;i--)
	{
		
		if(height[i]>standard_right)
		{
			standard_right=height[i];
		}
		if(height[i]<=standard_right)
		{
			res=res+standard_right-height[i];
		}
	}
	
//������ 
	printf("%lld\n",res); 
	
	} 
	return 0;
}


