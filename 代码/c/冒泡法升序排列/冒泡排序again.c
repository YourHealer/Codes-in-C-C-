#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*��������ѡ�񷨵ģ����Ǿ��û�������ð�ݱȽ��㡣*/

int main(int argc, char *argv[]) {
	int num[10];
	int i;
	int j;
	for(i=0;i<10;i++)
	{
		scanf("%d",&num[i]);
	 } 
	 for(i=0;i<9;i++)
	 {
	 	for(j=0;j<9-i;j++)
	 	{
	 		if(num[j]>num[j+1])
	 		{
	 			int temp;
	 			temp=num[j];
	 			num[j]=num[j+1];
	 			num[j+1]=temp;
			 }
		 }
	 }
	 for(i=0;i<10;i++)
	 {
	 	printf("%d\t",num[i]);
	 }
	return 0;
}
