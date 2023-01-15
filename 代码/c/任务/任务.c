#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ṹ������ 
typedef struct Time
{
	int begin;
	int over;	
}Time; 

//����ṹ������
Time task[300010];
Time replace[300010]; 

//����ѭ������
int i;
int j;

//��¼��
int counter=1; 

void _mergesort(int start,int end)
{
	//�ݹ����ֹ������������Ԫ���Ѿ��ǵ���ֵ���޷��١���ȥ�� 
	if(start>=end) return;
	
	//��Ѱ�м�λ�� 
	int mid=start+((end-start)>>1);
	
	//����������Ҷ˵� 
	int istart1=start,iend1=mid;
	//����������Ҷ˵� 
	int istart2=mid+1,iend2=end; 
	
	//������� 
	_mergesort(istart1,iend1);
	_mergesort(istart2,iend2); 
	
	int ii=start;
	
	//����/��������һ��û�кϲ�������ǰ���� 
	while((istart1<=iend1)&&(istart2<=iend2))
	{
		if(task[istart1].over<=task[istart2].over)
		{
			replace[ii++].over=task[istart1++].over;
			ii--;istart1--;
			replace[ii++].begin=task[istart1++].begin;
		}
		else
		{
			replace[ii++].over=task[istart2++].over;
			ii--;istart2--;
			replace[ii++].begin=task[istart2++].begin;
		}
		
	}
	
	//ĳ�����������ϲ���� 
	while(istart1<=iend1)
	{
		 replace[ii++].over=task[istart1++].over;
		 ii--;istart1--;	
		 replace[ii++].begin=task[istart1++].begin;
	 }
	while(istart2<=iend2) 
	{
		 replace[ii++].over=task[istart2++].over;
		 ii--;istart2--;	
		 replace[ii++].begin=task[istart2++].begin;
	}
	
	//���п��� 
	memcpy(task+start,replace+start,(end-start+1)*sizeof(Time));
}


void mergesort(int len) 
{
  if (len<2) return;  
  
  _mergesort(0,len-1);  // ���õݹ麯����������
}
 

int main()
{
	//������������ 
	int n;
	
	//��ʼ�� 
	memset(task,0,sizeof(task));
	memset(replace,0,sizeof(replace));
	
	//����
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&task[i].begin,&task[i].over);
	}
	
	//���ṹ�����鰴�ս���ʱ����й鲢���� 
	mergesort(n);
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(task[j].begin>=task[i].over)
			{
				counter++;
				i=j-1;
				break;
			}
	
		
		}
		
	 } 
	
	printf("%d\n",counter);
	
	return 0;	
} 
