#include <stdio.h>  
#include <stdlib.h>  
  
char com[1000005];   
int i=0;  
int j=0;  
char check(int pos);  
  
int main()   
{  
    //��������   
    while(~scanf("%c",&com[i]))  
    {  
        i++;  
    }  
      
    //�����޸ĺ���   
    for(j=0;j<i;j++)  
    {  
        printf("%c",check(j));  
    }  
      
    return 0;  
}  
  
char check(int pos)  
{  
    //Сд��ĸ   
    if(97<=com[pos]&&com[pos]<=122)  
    {     
        //��һ���ǻ��з� �� ��һ���ǿո� ����һ���Ǿ��/�ʺ�/��̾��   
        if((pos==0)||(com[pos-1]=='\n')||((com[pos-1]==' ')&&((com[pos-2]==33)||(com[pos-2]==46)||(com[pos-2]==63))))  
        {  
            com[pos]=com[pos]-32;  
        }  
    }  
      
    //��Сд��ĸ   
    else  
    {   //��д��ĸ   
        if(65<=com[pos]&&com[pos]<=90)  
        {  
            if((pos==0)||(com[pos-1]=='\n')||((com[pos-1]==' ')&&((com[pos-2]==33)||(com[pos-2]==46)||(com[pos-2]==63))))  
            {  
              
            }  
            else  
            {  
                com[pos]=com[pos]+32;  
            }  
        }  
    }   
      
    return(com[pos]);  
      
}
