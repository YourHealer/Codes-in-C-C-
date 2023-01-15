#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define capa 110
#define dis 55

using namespace std;

const int dir[4][2]={1,0,-1,0,0,1,0,-1};	//���巽������

struct pos
{
	int x;
	int y;
	int z;
	int step;								//����ṹ�壬������ͼ�ϵ�x��yλ�ü�ʱ����������λ�õ���������
};

queue <pos> q;								//�������
char mapp[capa][capa];						//�����ͼ
bool vis[capa][capa][dis];					//����ִ����
int n,m,k,T;								//����������������������ʧ���
int res;									//����������								
int sta_x,sta_y;							//��ڵ�x��y����
int end_x,end_y;							//���ڵ�x��y����
bool finish;								//�ж��Ƿ񵽴��յ�
pos beginn;	
pos curr;
pos nxt;
					
int main() 
{
	scanf("%d",&T);							//������

	
	for(int i=0;i<T;i++)
	{
		sta_x=0,sta_y=0;							
		end_x=0,end_y=0;
		
		scanf("%d%d%d",&n,&m,&k);				//�С��С���ʧ���
							  
		memset(mapp,0,sizeof(mapp));			//��ʼ��
		memset(vis,0,sizeof(vis));	
		for(int j=0;j<n;j++)					//�����ͼ
		{
			scanf("%s",mapp[j]);
			for(int u=0;u<m;u++)
			{
				
				if(mapp[j][u]=='S')
				{
					sta_x=j;
					sta_y=u;
					beginn.x=sta_x;
					beginn.y=sta_y;
				}
				if(mapp[j][u]=='E')
				{
					end_x=j;
					end_y=u;
				}
			}
		}		

		finish=false;						//��ʼ��Ϊû���ҵ�����

		q.push(beginn);						//��ʼ����ʼ����,��ѹ�����
		vis[beginn.x][beginn.y][beginn.z]=1;//�����ʼλ�þ�����
		
		while(q.size()!=0)
		{
			curr=q.front();					//�Ƕ�
			q.pop();						//����
			
			if((curr.x==end_x)&&(curr.y==end_y))	//�ҵ�����
			{
				res=curr.step;
				finish=true;
				break;
			}
			
			
				for(int j=0;j<4;j++)
				{
					
					nxt.x=curr.x+dir[j][0];
					nxt.y=curr.y+dir[j][1];
					nxt.z=curr.z+1;
					nxt.step=curr.step+1;
					
					//�йֳ�û
					if((curr.z+1)%k)
					{
						if(nxt.x<0||nxt.x>(n-1)||nxt.y<0||nxt.y>(m-1)||mapp[nxt.x][nxt.y]=='#'||mapp[nxt.x][nxt.y]=='*'||vis[nxt.x][nxt.y][(nxt.z)%k]==1)
						{
						continue;				
						}
					}
					//�޹ֳ�û
					else if(nxt.x<0||nxt.x>(n-1)||nxt.y<0||nxt.y>(m-1)||mapp[nxt.x][nxt.y]=='#'||vis[nxt.x][nxt.y][(nxt.z)%k]==1)
						{
							continue;
						}
						
					vis[nxt.x][nxt.y][(nxt.z)%k]=1;
					q.push(nxt);
	
				}
			
		}	
		//�ҵ�����
			if(finish)
			{
				printf("%d\n",res);
			}
		//û�ҵ�����
			else
			{
				printf("%d\n",-1);
			}
			
			while(q.size()!=0)
			{
				q.pop();
			}								//��ն���
		
	}
	return 0;
}
