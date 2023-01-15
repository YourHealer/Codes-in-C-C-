#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <vector>
#define capacity 300005
using namespace std;

int res=-1;
int m;			//���������
vector <int> nxt[capacity];		//����ͼ������

//����ṹ�� �����������ֺ�β��
struct Word
{
	int num;	//��¼����
	int step;	//�ߵ�����Ĳ���
};

bool flag[capacity];			//��¼�Ƿ�ʹ�ù�

Word curr;
Word pre;
queue <Word> q;					//����ѹ��/��������Ķ���

int main() 
{
	scanf("%d",&m);
	
	int	rec1,rec2,rec3,rec4;			//������ձ���
	
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&rec1,&rec2,&rec3,&rec4);
		nxt[rec1].push_back(rec4);		//���봢������
	}
	
	int sta_b,sta_e,end_b,end_e;		//���忪ʼ�������β�ֺͽ����������β��
	
	scanf("%d%d%d%d",&sta_b,&rec1,&rec2,&sta_e);
	scanf("%d%d%d%d",&end_b,&rec3,&rec4,&end_e);	//���뿪ʼ����������
							
	if((sta_b==end_b)&&(rec1==rec3)&&(rec2==rec4)&&(sta_e==end_e))
	{
		printf("%d\n",1);			//����1 ֻ�õ�һ������
		return 0;
	}
	else if(sta_e==end_b)
		{
			printf("%d\n",2);		//����2 ֻ�õ���������
			return 0;
		}
		else						//����
		{
		curr.num=sta_e;
		curr.step=1;
		q.push(curr);
		
		while(q.size()!=0)
		{
			pre=q.front();		//ȡ��
			flag[pre.num]=true;	//�ù�
			q.pop();			//����

			int amo=nxt[pre.num].size();
			
			for(int i=0;i<amo;i++)
				{
						curr.num=nxt[pre.num][i];
						if(flag[curr.num]) continue;
						else
						{
							curr.step=pre.step+1;
							q.push(curr);
							flag[curr.num]=true;
							if(curr.num==end_b)
							{
								res=curr.step+1;
								break;
							}
						}
				}
		if(res!=-1) break;
		}
		printf("%d\n",res);
		}
	
	return 0;
}
