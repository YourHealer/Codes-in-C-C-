#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num[10];
	printf("�������������Ԫ�ظ���\n");
	int many;
	int i;
	scanf("%d",&many);
	
	printf("����������Ԫ�أ�"); 
	for(i=0;i<many;i++)
	{
		scanf("%d",&num[i]); 
	 } 
	 for(i=many-1;i>=0;i--)
	 {
	 	printf("%d\t",num[i]);
	 }
	return 0;
}
