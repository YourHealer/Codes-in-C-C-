#include <stdio.h>
#include <stdlib.h>

void output(int* pointer1,int* pointer2);

int main() 
{
	int a,b;
	printf("��������������\n");
	scanf("%d%d",&a,&b);
	
	output(&a,&b);
	printf("�����ɴ�СΪ��%d %d��\n",a,b);
	
	return 0;
}
/*����ָ�뽻������
void output(int* pointer1,int* pointer2)
{
	int temp;
	if((*pointer1)<(*pointer2))
	{
		temp=*pointer1;
		*pointer1=*pointer2;
		*pointer2=temp;
	}
}*/

/*����ָ�뽻����ַ*/

void output(int* pointer1,int* pointer2)
{
	int* address;
	if((*pointer1)<(*pointer2))
	{
		address=pointer1;
		pointer1=pointer2;
		pointer2=address;
	}
/*	printf("%d %d.",*pointer1,*pointer2);  �������������ȷ�Ľ���� 
������Ϊ�����������������ʵ�Σ�Ҫ�ı��Ҳ��ʵ�Ρ�
��������pointer���βΣ���pointer���в����޷��ı�ʵ�Σ�ֻ���ڴ˺��������á�* �����з��ʲ����޸����ݡ�*/
 } 
