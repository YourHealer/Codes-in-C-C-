#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void order(char** string,int number);
void output(char** string,int number);

int main() 
{                                                                    /*��ָ����Ϊ���飬�ֱ�ָ��ÿ���ַ��������ַ��ĵ�ַ*/ 
	char* pointer[]={"air","none","language","boom"};                /*��������֪�ַ����ķ�������ʡ�ڴ�*/ 
	int num=4;
	
	order(pointer,num);
	output(pointer,num);
	
	return 0;
}

void order(char** string,int number)
{
	int index;
	int jacket;
    char* temp;
    
	for(index=0;index<number-1;index++)
	{
		for(jacket=0;jacket<number-index-1;jacket++)
		{
			if(strcmp((*(string+jacket)),(*(string+jacket+1)))>0)
			{
				temp=*(string+jacket);
				*(string+jacket)=*(string+jacket+1);
				*(string+jacket+1)=temp;
			}
		}
	}
}

void output(char** string,int number)
{
	int index;
	for(index=0;index<number;index++)
	{
		printf("%s\n",*(string+index));             /*ǧ��Ҫע�⣬������*(string+index)������(string+index)
		                                              ǰ���Ƕ�Ӧ�ַ������ַ��׵�ַ�������Ƕ�Ӧ�ַ����Ķ�Ӧָ��ĵ�ַ*/ 
	}
}
