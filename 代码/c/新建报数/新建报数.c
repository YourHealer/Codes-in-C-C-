#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
  
//��ʼ����ֵ   
int x;   
  
//��վλ��   
char pos_1[1005];  
int pos_2[1005];  
  
//��ѭ���ڳ��ȵ�ʮ������������  
int non[3];   
  
//��ȡ������ַ�   
char c;  
   
//ѭ������  
int i,j,k,t;  
  
//����j  
int j_copy;   
  
//վλ�ַ����鳤��  
int length_n=0;  
int length_dividend=0;   
  
//��¼����λ������  
int array[1000];  
  
//ȡ��ʱ��  
int temp=0;  
  
//����ѭ���ڳ���   
int dividend=0;  
int divisor=0;  
  
//�����־����  
int flag=0;  
  
//����ģ   
int mod;  
  
int u;  
int n=0;  
  
int main()   
{  
          
//��ʼ������   
    memset(array,0,sizeof(array));  
    memset(pos_1,0,sizeof(pos_1));  
    memset(pos_2,0,sizeof(pos_2));  
      
//������������վλ  
    scanf("%d",&x);  
      
//���ջس���   
    getchar();  
      
//��վλֵ�����ַ��������룬һλλ��ȡ������λ�����м���   
    for(i=0;(c=getchar())!='\n';i++)  
    {  
        pos_1[i]=c;  
        length_n++;  
    }  
  
    array[0]=x;  
      
//ѭ�������1000�ֿ���   
    for(i=0;i<1000;i++)  
    {  
        // ����ȡ����λ����   
        temp=x*array[i];  
        if((temp>=0)&&(temp<1000))  
        {  
            array[i+1]=temp;  
        }  
        else if(temp>=1000)    
            {  
                array[i+1]=temp%1000;  
            }  
              
        //�ж��������Ƿ��ظ�������ظ��ͽ���ѭ��   
        for(j=0;j<i+1;j++)  
        {  
            if(array[i+1]==array[j])  
            {  
                flag=1;  
                break;      
            }  
        }  
          
        if(flag==1)  
        {  
            break;  
        }  
    }  
      
    //ȷ������������ѭ���ڳ���   
    dividend=i+1-j;  
      
    //���и߾��ȼ������㣬ȷ������  
  
    //����ѭ���ڳ���ת��Ϊ��λ������������洢  
        j_copy=j;     
      
        if((j_copy>=1)&&(j_copy<10))  
        {  
            non[0]=j_copy;  
            non[1]=0;  
            non[2]=0;   
        }   
          
        if((j_copy>=10)&&(j_copy<100))  
        {  
            non[0]=j_copy%10;  
            non[1]=j_copy/10;  
            non[2]=0;  
        }  
      
        if((j_copy>=100)&&(j_copy<1000))  
        {  
            non[0]=j_copy%10;  
            non[1]=(j_copy/10)%10;  
            non[2]=(j_copy/10)/10;  
        }  
          
        //��վλ���ַ����鵹���滻Ϊ��������  
        for(t=0;t<length_n;t++)  
        {  
            pos_2[t]=pos_1[length_n-1-t]-'0';  
        }  
          
        //��������м�������   
        for(k=0;k<length_n;k++)  
        {  
            pos_2[k]=pos_2[k]-non[k];  
                if(pos_2[k]<0)  
                {  
                    pos_2[k+1]-=1;  
                    pos_2[k]+=10;   
                }  
        }   
          
  
          
        //����ѭ���ڳ���ȷ��������ʽ�����ÿ�γ����ĳ���   
        if((dividend>=1)&&(dividend<10))  
        {  
            length_dividend=1;  
        }  
        else if((dividend>=10)&&(dividend<100))  
        {  
            length_dividend=2;  
        }  
            else if((dividend>=100)&&(dividend<1000))  
                {  
                    length_dividend=3;  
                }  
    
     
        //ȷ����ʼ����   
        for(k=0;k<length_dividend;k++)  
        {  
            divisor=divisor+pow(10,length_dividend-k-1)*(pos_2[length_n-(k+1)]);  
        }  
   
        //�������   
        for(k=0;k<length_n-length_dividend+1;k++)  
        {  
            divisor=divisor%dividend;  
          
            if(k!=length_n-length_dividend)  
            {   
                divisor=10*divisor+pos_2[length_n-length_dividend-(k+1)];  
            }  
  
        }  
  
    //վλû�н���ѭ�� ����ʵ�ֲ���   
      
    if(length_n==1)  
    {  
        u=pos_1[0]-48;  
    }  
    if(length_n==2)  
    {  
        u=(pos_1[0]-48)*10+(pos_1[1]-48);  
    }  
    if(length_n==3)  
    {  
        u=(pos_1[0]-48)*100+(pos_1[1]-48)*10+pos_1[2]-48;  
    }  
    if(length_n>3)  
    {  
        u=(pos_1[length_n-4]-48)*1000+(pos_1[length_n-3]-48)*100+(pos_1[length_n-2]-48)*10+(pos_1[length_n-1]-48);  
    }  
      
    for(i=length_n-1;i>=0;i--)  
    {  
        n=n+(pos_1[i]-48)*pow(10,length_n-i-1);  
    }  
        if(j>u)  
        {  
            printf("%d\n",array[n-1]);  
        }  
      
    //վλ����ѭ��  
        else  
        {   //�������Ϊ0������Ϊ��-1������+length_dividend    
            if(divisor==0)  
            {  
                divisor=divisor+dividend;  
            }  
      
            printf("%d\n",array[j+divisor-1]);  
      
        }  
  
  
    return 0;  
}  
? ��ǧ���ġ��������İ�
����...
