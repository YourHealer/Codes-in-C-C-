#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�������Ľṹ�����ͣ��������Ѷȼ�����ֵ 
typedef struct dragon
{
	int com;
	int exp;
 } Dragon;

//����ṹ�����鴢��������Ϣ 
	Dragon arr_plus[200010];
	Dragon arr_minus[200010];
	
//������������ 
	int num;
	int n_plus=0;
	int n_minus=0; 
	
//����ѭ������
    int i;	
    
//����Ҫ����Ǯ
	long long int money=0;
	 
//������ҹ�����
	long long int power=0; 
	
//������ձ��� 
	int rec1=0;
	int rec2=0;

//������ź����еıȽϺ���	 
int compare1(const void* a,const void* b)
{
	Dragon* pa=(Dragon*)a;
	Dragon* pb=(Dragon*)b;
	return((pa->com)-(pb->com));
}

int compare2(const void* a,const void* b)
{
	Dragon* pa=(Dragon*)a;
	Dragon* pb=(Dragon*)b;
	return (((pb->com)+(pb->exp))-((pa->com)+(pa->exp)));
}
    
int main()
{
	//�����ʼ�� 
	memset(arr_plus,0,sizeof(arr_plus));
	memset(arr_minus,0,sizeof(arr_minus));
	
	//���� 
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		//�����Ѷ�ֵ�뾭��ֵ 
		scanf("%d",&rec1);
		scanf("%d",&rec2);
		if(rec2>=0)
		{
			arr_plus[n_plus].com=rec1;
			arr_plus[n_plus].exp=rec2;
			n_plus++;
		} 
		if(rec2<0)
		{
		 	arr_minus[n_minus].com=rec1;
			arr_minus[n_minus].exp=rec2;	
			n_minus++;
		}
	} 
	
	//�Ծ���ֵ�Ǹ��������վ���ֵ��С��������
	qsort(arr_plus,n_plus,sizeof(Dragon),compare1); 
	
	// �Ծ���ֵ�Ǹ��������б������ܴ���ʹ򣬴򲻹�����봽�
	for(i=0;i<n_plus;i++)
	{
		if(power>=arr_plus[i].com)
		{
			power+=arr_plus[i].exp;
		}
		else
		{
			money+=(arr_plus[i].com-power);
			power=arr_plus[i].com;
			power+=arr_plus[i].exp;
		}
	}
	
	//�Ծ���ֵΪ���������գ��Ѷ�+����ֵ���Ӵ�С���� 
	qsort(arr_minus,n_minus,sizeof(Dragon),compare2); 
	
	//�Ծ���ֵΪ���������б������ܴ���ʹ򣬴򲻹�����봽� 
	for(i=0;i<n_minus;i++)
	{
		if(power>=arr_minus[i].com)
		{
			power+=arr_minus[i].exp;
		}
		else
		{
			money+=(arr_minus[i].com-power);
			power=arr_minus[i].com;
			power+=arr_minus[i].exp;
		}
	}
	
	//�������
	printf("%lld\n",money); 
	return 0;
}
