#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define cash 1000

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float ratio5years=0.03;
	float ratio3years=0.0275;
	float ratio2years=0.021;
	float ratio1year=0.015;
	float ratiodynamic=0.0035;
	
	printf("һ�δ�5�����ϢΪ��\n");
	printf("%.2f\n",cash*(5*ratio5years));
	printf("�ȴ�2�꣬�ٴ�3�����ϢΪ��\n");
	printf("%.2f\n",cash*(1+2*ratio2years)*(1+3*ratio3years)-cash);
	printf("�ȴ�3�꣬�ٴ�2�����ϢΪ��\n");
	printf("%.2f\n",cash*(1+3*ratio3years)*(1+2*ratio2years)-cash);
	printf("��δ�1�����ϢΪ��\n");
	printf("%.2f\n",cash*(1+ratio1year)*(1+ratio1year)*(1+ratio1year)*(1+ratio1year)*(1+ratio1year)-cash);
	printf("����ڵ���ϢΪ��\n");
	printf("%.2f\n",cash*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)*(1+0.25*ratiodynamic)-cash);
	 
	 
	return 0;
}
