#include <stdio.h>
#include <stdlib.h>

int function_gcd(int n1,int n2)
{
	int result;
	
	int min;
	min=(n1>n2?n2:n1);                      /*���Լ��*/ 
	
	int i;
	for(i=1;i<=min;i++)
	{
		if((n1%i==0)&&(n2%i==0))
		{
			result=i;
		}
		
	}
	return(result);
	
 } 
 
 
 int function_lcm(int n1,int n2)
 {
 	int result;
 	
 	int jacket1;
 	int jacket2;
                                                      /*��С������*/ 
 	jacket1=n1/(function_gcd(n1,n2));
 	jacket2=n2/(function_gcd(n1,n2));
 	
 	result=jacket1*jacket2*(function_gcd(n1,n2));
 	
 	return(result);
 }


int main() 
{
	 
	int num_1,num_2; 
	int gcd;
	int lcm;
	
	printf("�������������Լ������Լ������С��������\n");
	scanf("%d%d",&num_1,&num_2);
	gcd=function_gcd(num_1,num_2);
	lcm=function_lcm(num_1,num_2);
	
	printf("���Լ��Ϊ%d��\n",gcd);
	printf("��С������Ϊ%d��\n",lcm);
	
	return 0;
	
}
