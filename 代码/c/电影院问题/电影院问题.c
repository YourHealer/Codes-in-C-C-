#include <stdio.h>
#include <stdlib.h>

int information_age(int order)
{
	int age;
	if(order==1)
	{
		age=10;
	}
	if(order>1)
	{
		age=information_age(order-1)+2;
	}
	return(age);
 } 

int main() {
	int num;
	printf("������ڼ����˵����䣿\n");
	scanf("%d",&num);
	int result;
	result=information_age(num);
	printf("��%d���˵�������%d�ꡣ\n",num,result);
	return 0;
}
