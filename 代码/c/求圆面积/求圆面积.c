/*
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926 

int main(int argc, char *argv[]) {
	double r;                                    ���ں��ڶ���������ʽ 
	double square;
	scanf("%lf",&r);
	square=PI*r*r;
	printf("%.2lf\n",square);
	return 0;
}
*/

#include <stdio.h>
#define PI 3.1415926
#define square(r) PI*r*r                         /*�ں괦����������ʽ*/ 

int main(){
	double r;
	scanf("%lf",&r);
	printf("%.2lf\n",square(r));
	
}
