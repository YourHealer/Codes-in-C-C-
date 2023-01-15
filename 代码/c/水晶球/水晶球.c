#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ˮ����
typedef struct diamond
{
	int len;
	int	wid;
	int hei;
	int ord;
} Dia;

//����ƴ��ˮ���� 
typedef struct find
{
	int sum;
	int pos1;
	int pos2;	
}Find;
 
//����ˮ��������
int num;

//����ˮ��������
Dia arr[100010];
Find joint[100010];
 
//����ѭ������
int i;

//������ձ���
int rec1=0,rec2=0,rec3=0; 

//�����������������ͳ���ж��ٸ���ƴ�Ӻ��ˮ����
int counter; 

//�������ֵ�ű���� 
int max1=0; 
int max2=0; 

//���彻������
void swap(int* a,int* b)
{
	(*a)^=(*b);
	(*b)^=(*a);
	(*a)^=(*b);	
} 

//qsort�еıȽϺ��� 
int compare(const void* a, const void* b)
{
	Dia* pa=(Dia*)a;
	Dia* pb=(Dia*)b;
	
	if((pb->len)==(pa->len))
	{
		if((pb->wid)==(pa->wid))
		{
			return((pb->hei)-(pa->hei));
		}
		else return((pb->wid)-(pa->wid));
	}
	else return((pb->len)-(pa->len));
}

//������ 
int main()
{
	//��ʼ������
	memset(arr,0,sizeof(arr)); 
	memset(joint,0,sizeof(joint));
	
	//����ˮ��������
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		//�����ˮ������Ϣ
		scanf("%d",&rec1);
		scanf("%d",&rec2);
		scanf("%d",&rec3);
		
		//�������� 
		if(rec1<rec2)
		{
			swap(&rec1,&rec2);
		}
		if(rec1<rec3)
		{
			swap(&rec1,&rec3);
		}
		if(rec2<rec3)
		{
			swap(&rec2,&rec3);
		}
		
		//��ˮ������Ϣ���ӳ����̴��볤�������У�����ˮ�����Ŵ���ṹ������ 
		arr[i].len=rec1; 
		arr[i].wid=rec2;
		arr[i].hei=rec3;
		arr[i].ord=i;
		
	}
	qsort(arr,num,sizeof(Dia),compare);
	
	for(i=0;i<num;i++)
	{
		if(arr[i].hei>arr[max1].hei)
		{
			max1=i;
		}
	}
	//ֻ��Ҫ�����ͺã�����ֻѡ��һ��ˮ��ʯ����� �������ɵ�ˮ��������뾶��(arr[max1].hei) /2,��Ӧ�������max1+1
	

	
	for(i=0;i<num-1;i++)
	{
		if((arr[i].len==arr[i+1].len)&&(arr[i].wid==arr[i+1].wid))	
		{
			//��¼��������ˮ��ʯ 
			joint[counter].pos1=arr[i].ord;
			joint[counter].pos2=arr[i+1].ord;
			
			// 
			if((arr[i].hei+arr[i+1].hei)<arr[i].wid)
			{
				joint[counter].sum=(arr[i].hei+arr[i+1].hei);
				
			}
			else joint[counter].sum=arr[i].wid;
			
			counter++;
		}
	} 
	
	for(i=0;i<counter;i++)
	{
		if(joint[i].sum>joint[max2].sum)
		{
			max2=i;
		}
	}
	
	if((arr[max1].hei)>(joint[max2].sum))
	{
		printf("%d\n",1);
		printf("%d\n",arr[max1].ord+1);
	}
	else
	{
		printf("%d\n",2);
		printf("%d %d\n",joint[max2].pos1+1,joint[max2].pos2+1);
	}
	
	return 0;
}
