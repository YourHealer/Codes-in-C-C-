#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	int num=0;
	int i;
	printf("����Ҫ����Ȼ����͵����٣�\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		num+=i;
	}
	printf("��ͽ���ǣ�%d.\n",num);
	return 0;
}
