#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int n=0;					//���
long long arr[200010];		//������
long long arrtmp[200010];	//����1��0��ɵ���ʱ����
stack <long long> hei;		//��ջ

int main()
{
	while(~scanf("%d", &n))					//���뵽eof
	{	
		long long max=0;						//���岢��ʼ�����߶�		
		memset(arr, 0, sizeof(arr));			//��ʼ��
		memset(arrtmp, 0, sizeof(arrtmp));		//��ʼ��
		while (!hei.empty())
		{
			hei.pop();	
		}										//���ջ

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
			if (arr[i] > max)
			{
				max = arr[i];
			}					
		}										//���벢�ҳ����ֵ
		for (int i = 0; i < n; i++)
		{
			arrtmp[i] = (max - arr[i]) % 2;		//����ʱ���鸳ֵΪ0��1
				if (hei.empty())
				{
					hei.push(arrtmp[i]);
				}
				else
				{
					(arrtmp[i] == hei.top()) ? hei.pop() : hei.push(arrtmp[i]);
				}
		}										
		if(hei.size() <= 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	
		
	}
	
	return 0;
}
