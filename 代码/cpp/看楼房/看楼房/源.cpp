#include <iostream>  
#include <cstring>   
#include <stack>  
using namespace std;

//����   
long long color[1000010]; //��¼¥����ɫ  
long long height[1000010]; //��¼¥���߶�   
long long repeat[1000010]; //�ж��Ƿ��ظ�   
int amo; //��¼��������  
int n; //��¼¥���߶�  


stack<long long> c; //������ɫջ  
stack<long long> h; //����߶�ջ   
int main()
{
    cin >> amo;
    for (int j = 0; j < amo; j++)    //ÿ������   
    {
        long long cnt = 0; //�������������ʼ��Ϊ0   

        memset(color, 0, sizeof(color));
        memset(height, 0, sizeof(height));
        memset(repeat, 0, sizeof(repeat)); //��ʼ��   

        while (!h.empty())
        {
            h.pop();
            c.pop();
        }               //���ջ   

        cin >> n; //���뷿�Ӹ���   
        for (int i = 0; i < n; i++)
        {
            cin >> color[i];  //������ɫ   
        }
        for (int i = 0; i < n; i++)
        {
            cin >> height[i]; //����߶�   
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0) //�ѵ�һ��߶�����ɫ����,����������  
            {
                h.push(height[0]);
                c.push(color[0]);
                repeat[color[0]]++;
                cnt++;
            }
            else        //��������߶�����ɫ����   
            {
                if (height[i] >= h.top()) //��ǰ¥���߶ȴ��ڻ����ջ���߶�   
                {
                    if (!h.empty())
                    {
                        do
                        {
                            h.pop();
                            repeat[c.top()]--;
                            if (repeat[c.top()] == 0)
                            {
                                cnt--;
                            }
                            c.pop();

                        } while (!h.empty() && height[i] >= h.top());
                    }


                }
                h.push(height[i]);
                if (repeat[color[i]] == 0) cnt++;
                repeat[color[i]]++;
                c.push(color[i]);
                //���ظ�������  
            }

            printf("%lld%c", cnt, (i == n - 1 ? '\n' : ' '));       //�������   
        }
    }
    return 0;
}