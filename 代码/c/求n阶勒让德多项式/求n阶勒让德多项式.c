#include <stdio.h>
#include <stdlib.h>

float Legendre(float x,int n)
{
	float c;
	
	if (n==0) c=1;
	else if (n==1) c=x;
	     else 
		 {
		 	c=((2*n-1)*x*Legendre(x,n-1)-(n-1)*Legendre(x,n-2))/n;
		 } 
	
	return(c);
}


int main() 
{
	float x;
	int n;
	
	printf("�������Ա���ֵ�����õ½�����\n");
	scanf("%f%d",&x,&n);
	
	float result;
    result=Legendre (x,n);
    printf("�����%.2f��\n",result);
    
	return 0;
}
