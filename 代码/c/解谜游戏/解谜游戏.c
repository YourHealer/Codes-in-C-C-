#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//�������� ���� ����ԭʼ��ť״������ 
	int n,m;
	int a[18][18];
	int b[18][18];
	int result=0;
	int res[100000];
	int sum;
	
//�������� 
void operate(int,int);
void onz(int*);
int compare(int total,int pointer[]);

int main() 
{
//����ѭ������
	int i,j,k; 
//�����������
	int counter;
//�����־����
	int flag; 

//��������������
	scanf("%d %d",&n,&m); 
//���� 
	sum=pow(2,m);
	
//����ԭʼ��ť״������,���ڷ��� 
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	} 


	
//���ڲ�ͬ�������ö��,k����ö���еĵڼ���ö������ 
for(k=0;k<sum;k++)
{
		counter=0;
		flag=0;
		
//����ԭʼ��ť�����ں�������
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			b[i][j]=a[i][j];
		}
	 } 

		
//��һ����ӵ�λ���i�Ű�ť 
		for(j=0;j<m;j++)
		{
			if((k>>j)&1)
			{
				operate(0,m-j-1);
				counter++;
			}
		}
		
//��ʣ�µ�ÿһ�н��в���
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<m;j++)
			{
				if(b[i][j]==1)
				{
					operate(i+1,j);
					counter++;
				}		
			}

		} 
		
//�����һ�е�����״�������ж�
		for(j=0;j<m;j++)
		{
			if(b[n-1][j]==1)
			{
				flag=1;
			}
		}
		
		if(flag==0)
		{
			res[k]=counter;
		}
		else res[k]=10000000;		
			
}
	
//�Բ�ͬ�Ĳ��������бȽ� 
	result=compare(sum,res);
	
//������	
	printf("%d\n",res[result]);
	
	return 0;
}

//�԰�ť��������Χ���ܹ������ť������Ϩ���� 
void operate(int row,int pos)
{
	onz(&b[row][pos]);
	onz(&b[row][pos-1]);
	onz(&b[row][pos+1]);
	onz(&b[row-1][pos]);
	onz(&b[row+1][pos]);
}

//���ı䰵�����ı��� 
void onz(int* num)
{
	if(*num==1) *num=0;
	else *num=1;
}

//�Ƚ�counter��Сֵ 
int compare(int total,int pointer[])
{
	int min=0;
	int t; 
	for(t=0;t<total;t++)
	{
		if(*(pointer+min)>=*(pointer+t))
		{
			min=t;
		}
	}
	return(min);
}

