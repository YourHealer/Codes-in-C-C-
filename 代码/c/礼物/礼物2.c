#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

//�ṩ������ 
char supply[200010];

//��Ҫ������ 
char want[10010];

//Ҫ����������
char operate[20020];

//��Ϊnext[i][j]=k,������iλ�õ����j��ĸ��λ����k
int next[200010][26];

//���崢����������
int res[10010]; 

//���崢����ѽ��������
int best[10010]; 

//����ѭ������ 
int i,j,k;
 
//�����־���� 
bool flag[200010];

//�����жϱ���
int circle;
int smaller; 

//�������鳤��
int length_supply;
int length_want; 

//��¼λ��
int pos; 
 
int main() 
{	
	//���� 
	scanf("%s%s",supply,want);
	
	memset(operate,0,sizeof(operate));
	
	//����������
	 strcpy(operate,want);
	 strcat(operate,want);
	  
	//��
	length_supply=strlen(supply);
	length_want=strlen(want) ;
	
	//����next 
	memset(next,-1,sizeof(next));
		
	//��ʼ��
	for(i=0;i<length_want;i++)
	{
		best[i]=10000000;
	}
	
	for(i=length_supply-1;i>=0;i--)
	{
		for(j=0;j<26;j++)
		{
			//û�и���������Ϣʱ��������һ������Ϣ 
			next[i][j]=next[i+1][j];
		}
			//����һ����ĸ������Ϣ��������λ�������ĳ��ĸΪ���� 
			next[i][supply[i]-'a']=i; 
	}

	
	for(i=0;i<length_want;i++)
	{
		//ÿ��ѭ��ǰ��ʼ��,�ӳ�ʼ0λ�ÿ�ʼ��������Գɻ��������Ž⣬����λ�������������һλ�� 
		pos=0;
		circle=1;
		smaller=1;
		memset(flag,0,sizeof(flag));
		
		for(j=0;j<length_want;j++)
		{
			//�жϱ�λ���Ƿ��ù�����û�ù��ñ�λ�þ��ã��ù�����ת����һλ�� 
			if(flag[pos])
			{
				pos++;
			}	
			//����λ����Ϣ 
			pos=next[pos][operate[i+j]-'a'];
			
			//����λ����Ϣ 
			res[j]=pos+1;
			
			//��Ǹ�λ���Ѿ����ù��� 
			flag[pos]=true;
			
			//��Ҫ����ĸ�ṩ����˵���޷��ɻ� 
			if(pos==-1)
			{
				circle=0;
				break;
			}
		}		
			//������Գɻ���Ҫ���бȽ� 
		if(circle)
		{
				for(k=0;k<length_want;k++)
				{
					if(res[k]<best[k])
					{
						
						break;
					}
					else if(res[k]>best[k])
					{
						smaller=0;
						break;
					}
		    	}
			
			
			//��������Ž�͸������Ž� 
			if(smaller)
			{
				for(k=0;k<length_want;k++)
				{
					best[k]=res[k];
				}
			} 
			
		}
		 
		
	} 
	
	//���,����������س����ǿո� 
	for (k=0;k<length_want;k++)
	{
		 printf("%d%c",best[k],k==length_want-1?'\n':' ');
	}
 
	return 0;
}
