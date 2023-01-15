#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Info
{
	int num;
	int top;
	int bot;	
}Info;							//������ӽṹ�� 

typedef struct New
{
	int side1;
	int side2;
}New;

int n;									//������Ʒ���� 
int m; 									//����������� 

Info box[100005];						//����������飬�˽�������е���Ʒ����������Ʒ���ײ���Ʒ 
New next[100005];						//������Ʒ���飬�˽���������Ʒ 
bool flag[100005];						//�����־���飬�жϸ���Ʒ�Ƿ��Ѿ������ 

int x=0,y=0;	//��������
int temp;		//��ʱ����
int i,j;		//ѭ������

int main() 
{	
	scanf("%d%d",&n,&m);
	
	//���Ӹ�ֵ
	for(i=1;i<=n;i++)
	{
		box[i].num=1;
		box[i].top=i;
		box[i].bot=i;
	}							
	memset(next,0,sizeof(next));
	memset(flag,0,sizeof(flag));//��ʼ��
	
	//��λ����
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);			//�����������
		if(box[x].num==0)
		{
			continue;					//x��Ϊ��
		}
		else if(box[y].num==0)			//y��Ϊ��
			{
				//y��Ϊ�յ�next���� 
				box[y].num=box[x].num;
				box[y].top=box[x].bot;
				box[y].bot=box[x].top;	//����y�� 
				
				box[x].num=0;
				box[x].top=0;
				box[x].bot=0;			//���x��
			}
			else 						//x,y�о�����
			{
				//����next�������о��ǿյ�ǰ����
				if(next[box[y].top].side1==0)
				{
					next[box[y].top].side1=box[x].top;
				}
				else if(next[box[y].top].side2==0)
					 {
						 next[box[y].top].side2=box[x].top;
					 }
				
				
				if(next[box[x].top].side1==0)
				{
					next[box[x].top].side1=box[y].top;
				}
				else if(next[box[x].top].side2==0)
					{
						next[box[x].top].side2=box[y].top;
					}
					else break;
	
				box[y].num+=box[x].num;
				box[y].top=box[x].bot; //����y�� 

				box[x].num=0;
				box[x].top=0;
				box[x].bot=0;			//���x��
			} 
	}
	
	//���
	for(i=1;i<=n;i++)
	{
		if(box[i].num==0)	//����Ϊ��
		{
			printf("0\n");
			continue;
		}
		else
		{
			//���ӷǿ� 
			printf("%d",box[i].num);
			temp=box[i].top;
			for(j=1;j<=box[i].num;j++)
			{
				printf(" %d",temp);
				flag[temp]=1;
				
				if((next[temp].side1!=0)&&(flag[next[temp].side1]==0))
				{
					temp=next[temp].side1;
				}
				else if((next[temp].side2!=0)&&(flag[next[temp].side2]==0))
					{
						temp=next[temp].side2;
					}
					else break;
			}
			printf("\n");
		}
	} 
	return 0;
}
