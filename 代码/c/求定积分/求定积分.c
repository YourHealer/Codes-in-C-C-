#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define pieces 200000

float fsin(float x);
float fcos(float x);
float fexp(float x);
float integral(float superior,float low,float (*pointer)(float));

int main() 
{
	float top,bottom;
	int flag;
	float (*pointer)(float value);
	 
	printf("�����붨���������ޣ�\n");
	
	printf("����Ϊ��\n");
	scanf("%f",&top);
	    printf("����Ϊ��\n");
	    scanf("%f",&bottom);
	
	printf("������ĸ��������л����أ�\n");
	printf("���Һ�����1�������Һ�����2����ָ��������3����\n");
	scanf("%d",&flag);
	
	switch(flag)
    {
    	
	case 1: 
	{
		pointer=fsin; 
		break;
	}
	
	    case 2:
	    	{
	    		pointer=fcos;
	    		break;
			}
			
		        case 3:
		        	{
		        		pointer=fexp;
		        		break;
					}
					
	}
	
	float result;

	result=integral(top,bottom,pointer);
	printf("���Ϊ��%f",result);
	
		return 0;
	
}

float fsin(float x)
{
	return(sin(x));
}

float fcos(float x)
{
	return(cos(x));
}


float fexp(float x)
{
	return(exp(x));
}

float integral(float superior,float low,float (*pointer)(float))
{
	float sum=0;
	float width=(superior-low)/pieces;
	float x=low; 
	int index=0;
	
	for(index=0;index<pieces;index++)
	{
		x=x+width;
		sum=sum+((*pointer)(x)*width);
	}
	
	return(sum);
}




