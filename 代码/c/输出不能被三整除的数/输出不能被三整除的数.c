#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	for(i=100;i<=200;i++)                 /*Ҫע���ܼƶ�101�������м��*/ 
	{
	if(i%3==0)                            /*��������3�ܷ��������á�%���ţ����ǡ�/���ţ�*/ 
	{
		continue;                         /*����continue�ĳ���ʹ�ý���������for���*/ 
		}	
		printf("%d ",i);
	 } 
	return 0;
}
