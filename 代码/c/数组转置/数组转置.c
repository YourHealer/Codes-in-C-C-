#include <stdio.h>
#include <stdlib.h>
#define value 10
void turn(int array[][value],int m,int n)
{
	int i;
	int j;
	int num[value][value];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			num[i][j]=array[j][i];
		}
	}
	
		for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",num[i][j]);                       /*���������ָ�룬��ֻ�ܽ�������������޷��ı�ֵ*/ 
		}
	}
	
}


int main(int argc, char *argv[]) {
	int num[value][value];
	int i,j;
	int m,n;
	
	printf("����������Ҫ�������С�\n");
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	
	turn(num,m,n);
	
	return 0;
}
