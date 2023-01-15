#include <iostream> 
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath> 

using namespace std;  
  
int main ()  
{  
    //����������������   
    long long amount;  
      
    //����ѧ������   
    long long num;  
      
    //�����ⲿ���ڲ�ѭ������   
    long long out;  
    long long in;   
      
    //����ѧ��λ��   
    long long x,y;  
      
    //������ʱ����   
    long long temp;  
      
    //����������   
    long long res_x,res_y;   
      
    //�����������   
    long long cnt;  
      
    //������������   
    scanf("%lld",&amount);  
      
    for(out=1;out<=amount;out++)  
    {     
        //��ʼ����������   
        cnt=0;  
          
        //����x���ȶ��С�y���ȶ���      
        priority_queue<long long,vector<long long>,less<long long> >x_big;  
        priority_queue<long long,vector<long long>,greater<long long> >x_small;  
        priority_queue<long long,vector<long long>,less<long long> >y_big;  
        priority_queue<long long,vector<long long>,greater<long long> >y_small;  
          
          
        //����ѧ������   
        scanf("%lld",&num);  
        printf("Case: %lld\n",out);   
          
        //��������   
        for(in=1;in<=num;in++)  
        {             
            scanf("%lld %lld",&x,&y);   
              
            //x    �жϴ���Ƿ�Ϊ��   
            if(x_big.empty())  
            {  
                //���Ϊ�գ���Ѷ�β����x�����Զ�����   
                x_big.push(x);  
            }     
            else  
            {   
                //��ѷǿ�,С��Ϊ��  
                if(x_small.empty())  
                {  
                    //�ж��������Ƿ���ڵ��ڴ�ѶѶ�ֵ   
                    if(x>=x_big.top())  
                    {  
                        //����ǣ���x����С�Ѷ�β�����Զ����� ;  
                        x_small.push(x);  
                    }   
                    else   
                    {  
                        //������ǣ�����ѶѶ�ֵ����С�Ѷ�β�������򣻴�Ѳ���x��������   
                        x_big.push(x); 
						temp=x_big.top(); 
						x_big.pop(); 
						x_small.push(temp); 
                    }  
                }  
                  
                //��Ѳ��գ�С�Ѳ��� �������ѵ�Ԫ�ظ�����ͬ   
                else if(!(x_big.size()-x_small.size()) ) 
                {  
                    // �ж�x�Ƿ�С�ڵ���С�Ѷ�ֵ   
                    if(x<=x_small.top())  
                    {  
                        //����ǣ���x������β�����Զ�����   
                       x_big.push(x);  
                    }  
                    else  
                    {  
                        //������� ����С�Ѷ�ֵ����temp���ٽ�֮������β�����Զ�����ɾ��С�Ѷ�ֵ��С��β����x�����Զ�����   
                       x_small.push(x);
					   temp=x_small.top();
					   x_small.pop(); 
					   x_big.push(temp);  

                    }  
                }  
                    //С�Ѳ��� �Ҵ�ѵ�Ԫ�ظ�������С�ѵ�Ԫ�ظ���  
                    else if(x_big.size()>x_small.size())  
                        {  
                            //�ж�x�Ƿ���ڵ���С�Ѷ�ֵ   
                            if(x>=x_big.top())  
                            {  
                                //����ǣ���x����С��β�����Զ�����  
                                x_small.push(x);  
                            }  
                            else   
                            {  
                                //������� ����x������β�����Զ������ٽ���Ѷ�ֵ����temp��ɾ����Ѷ�ֵ��С��β����temp�����Զ�����  
                                x_big.push(x);  
                                temp=x_big.top();  
                                x_big.pop();  
                                x_small.push(temp);  
                            }  
                        }  
            }  
                  
            //y ͬ��   
            if(y_big.empty())  
            {  
                y_big.push(y);  
            }  
            else  
            {  
                if((y_small.empty()))  
                {  
                    if(y>=y_big.top()) y_small.push(y);  
                    else   
                    {   y_big.push(y);
						temp=y_big.top();
						y_big.pop();  
                    	y_small.push(temp);

                    }  
                }  
                  
              
                else if(!(y_big.size()-y_small.size()) ) 
                    {  
                        if(y<=y_small.top())  
                        {  
                         y_big.push(y);  
                        }  
                        else  
                        {   y_small.push(y); 
							temp=y_small.top();
                            y_small.pop();  
                            y_big.push(temp); 
                        }  
                    }  
                    else if(y_big.size()>y_small.size())  
                        {  
                            if(y>=y_big.top())  
                            {  
                                y_small.push(y);  
                            }  
                            else   
                            {  
                                y_big.push(y);  
                                temp=y_big.top();  
                                y_big.pop();  
                                y_small.push(temp);  
                            }     
                        }  
            }  
            
			//ֻ�����������Ż������λ��  
            if(in%2)  
            {  
                //ȡ�Ѷ�ֵ   
                res_x=x_big.top();  
                res_y=y_big.top();  
            }  
              
            //����Ӻ�   
            cnt=cnt+llabs(res_x-x);  
            cnt=cnt+llabs(res_y-y);  
              
            //������   
            printf("%lld.0000\n",cnt);  
              
        }  
    }  
}  
