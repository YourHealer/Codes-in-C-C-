#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int num[40]={1,1};
	int value;
	int i; 
	for(i=2;i<40;i++)
	{
		num[i]=num[i-1]+num[i-2];
	 } 
	 printf("����֪��쳲���������ǰ��ʮ�������ĸ��أ�\n");
	 scanf("%d",&value); 
	 printf("%d\n",num[value-1]);
	return 0;
}
