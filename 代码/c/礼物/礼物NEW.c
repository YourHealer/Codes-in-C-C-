#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//��������ϵ����� 
	char supply[200005];
	
	//������Ҫ������ 
	char want[10005];
	
	//������Ҫ������ 
	char copy[20010];
	
	//������ֱ���
	int appear[10005]; 	
	
	//�����������
	char array[10000][10000];
	
	//������������
	char order[10000][10000]; 
	
	//��ʱ���� 
	char target[10000];
	 
	//����ѭ������
	int i=0,j=0,k=0,t=0;
	int satisfy=0;
	
	//���峤�ȱ���
	int length_want; 
	int length_supply;

	int key=0;
	
int main() 
{
	 
	//��ʼ��
	memset(supply,0,sizeof(supply));
	memset(copy,0,sizeof(copy)); 
	memset(want,0,sizeof(want));
	memset(appear,0,sizeof(appear));
	memset(order,0,sizeof(order));
	memset(array,0,sizeof(array));
	memset(target,0,sizeof(target)); 
	
	//��ʼ������
	gets(supply);
	gets(want);
	
	//���и��� 
	strcpy(copy,want);
	strcat(copy,want); 
	
	//�������鳤��
	length_want=strlen(want); 
	length_supply=strlen(supply);
	
	int min=0;
	 
	//k������ܵ���� 
	for(k=0;k<length_want;k++)
	{
		j=0;
		
		//i������ѡ���������� 
		for(i=0;i<length_supply;i++)
		{
			if(j<length_want)
			{
				if(copy[j+k]==supply[i])
				{
					appear[k]=appear[k]+1;
					array[k][j]=i+1;
					j++;
				}
			}
			else break;
		}
			
	}
	
	for(k=0;k<length_want;k++)
	{
		//ȫ�������ҵ�
		if(appear[k]==length_want)
			{
				strcpy(order[satisfy++],array[k]);	
			}
	}
	
	//�ҵ�counter��СֵΪorder[0] 
	for(k=0;k<satisfy-1;k++)
	{
		if(strcmp(order[k],order[k+1])<=0)
		{
			strcpy(target,order[k]);
			strcpy(order[k],order[k+1]);
			strcpy(order[k+1],target);
		}
	}
	
	for(k=0;k<length_want;k++)
	{
		printf("%d",order[satisfy-1][k]);
		if(k!=length_want-1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}

	return 0;
}
