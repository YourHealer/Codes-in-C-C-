#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a,b,c;
	float s,square;
	
	printf("�������������������ε����߳���\n");
	scanf("%f %f %f",&a,&b,&c);
	s=(a+b+c)/2;
	square=sqrt(1.0*s*(s-a)*(s-b)*(s-c));
	
	printf("��������������α߳�Ϊ��\n");
	printf("%.2f\t%.2f\t%.2f\t",a,b,c);
	printf("\n�������������Ϊ��\n");
	printf("%.2f",square);
	return 0;
}
