#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

//������������
int n;

//����ͬѧ����
int num;

//��������洢ÿһλͬѧ��x����
int x[500005];

// ��������洢ÿһλͬѧ��y����
int y[500005];

//����ѭ������
int i,j; 

int main() 
{
	//������������ 
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		for(j=0;j<num;j++)
		{
			scanf("%d",&x[j]);
			scanf("%d",&y[j]);
		}	
	} 
	return 0;
}
