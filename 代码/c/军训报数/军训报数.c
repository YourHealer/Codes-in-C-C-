#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//���������� 
int res=1;

//���ַ��������¼С��λ�� 
char array[1020];

//�����¼���� 
int record[5];

//���峤�ȱ��� 
int length;

//����ѭ������ 
int i=0;

int main()
{
	//������� 
	int x=0;
	int num=0;
	
	//�����жϱ��� 
	bool flag=false;
	
	//����������� 
	scanf("%d %s",&x,array);
	
	//�� 
	length=strlen(array);
	
	//�Գ��ȷ������� ��ֻ�к���λ���� 
	if(length==1)
	{
		num=array[length-1]-'0';
	} 
	else if(length==2)
		{
			num=(array[length-2]-'0')*10+array[length-1]-'0'; 
		}
		else if(length==3)
			{
				num=(array[length-3]-'0')*100+(array[length-2]-'0')*10+array[length-1]-'0';
			}
			//������λ�Ľ��в�1000��������ֹ��Ϊȡλ©��ѭ������ 
			else
			{
				num=1000+(array[length-3]-'0')*100+(array[length-2]-'0')*10+array[length-1]-'0';
			}
		
	for(i=0;i<num;i++)
	{
		res=res*x;
		if(res>=1000)
		{
			flag=true;
		}
		
		res=res%1000;
		//��λ 
		record[0]=res%10;
		//ʮλ 
		record[1]=(res/10)%10;
		//��λ 
		record[2]=res/100;
		
	}
	//����ѭ�� 
	if(flag)
	{
		printf("%d%d%d\n",record[2],record[1],record[0]);
	} 
	//û��ѭ�� 
	else printf("%d\n",res);
	
	return 0;
}
