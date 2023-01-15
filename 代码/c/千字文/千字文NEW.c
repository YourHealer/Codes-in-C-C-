#include "string.h"
#include "stdio.h"
#include "math.h"

int main()
{
	//����������ȡ�����ַ��ı��� 
    char ch1, ch2, ch3;
    //����ȼ۱��� 
    int t, tt, ttt;
	int m;
	int x, xx, xxx;
	//�������� 
    long zi[65536];
    //��������г�ʼ�� 
    memset(zi, 0, sizeof(zi));
 
 	//ʵ�ֽ�ֹ���� 
    while(scanf("%c", &ch1) != EOF)
    {
        t = ch1;
        if(t < 128)
        {
        //ASCII�룬�����ٶ����ַ� 
        	;	
		} 
            
        else if(t<224 && t>=192)
        {
        	//�ٶ���һ���ַ� 
            ch2 = getchar();
            //��ֵ 
            tt = ch2;
            //unicode�� 
            m = (t - pow(2, 7) - pow(2, 6)) * pow(2, 6) + tt - pow(2, 7);
 			//��unicode�����±� 
            zi[m]++;
        }
        	else
        	{
        	//�ٶ��������ַ� 
            ch2 = getchar();
            ch3 = getchar();
            //��ֵ 
            tt = ch2;
            ttt = ch3;
            //unicode�� 
            m = (t - pow(2, 7) - pow(2, 6) - pow(2, 5)) * pow(2, 12) + (tt - pow(2, 7)) * pow(2, 6) + ttt - pow(2, 7);
            //��unicode�����±� 
			zi[m]++;
        	}
            
    }
    
 	//�����Ǳ��� ���ڿ����ַ��Ƿ��ظ����� 
    int flag = 0;
    //ѭ������ 
    int i; 
    //���б��� ȷ���Ƿ�����ظ��ַ� 
    for (i = 0; i < 65536; i++)
    {
        if(zi[i] > 1)
        {
            flag = 1;
            break;
        }
    }
    
    //��ƪ���³����ظ��ַ� 
    if(flag == 1)
    {
    	// ��ASCII����濪ʼ���� 
        for (i = 128; i < 65536; i++)
        {
        	//utf-8���������ֽ����� 
            if(i >= 128 && i < 2048)
            {
                if(zi[i] > 1)
                {
                	//����һλutf-8����л�ԭ 
                    x = i/64 + 192;
                    //���ڶ�λutf-8����л�ԭ 
                    xx = i%64+128;
                    //x��ʾ��Сд��ʮ�������������4��ʾ�����ʮ���������Ŀ����4���ַ���0��ʾ�����ʮ���������У�����4���ַ��Ĳ��֣��á�0������ 
                    printf("%c%c 0x%04x %ld\n", x, xx, i, zi[i]);
                }
            }
 
            //utf-8���������ַ����� 
            else
            {
                if(zi[i] > 1)
                {	
                	//����һλutf-8����л�ԭ 
					x = i/4096+224;
					//���ڶ�λutf-8����л�ԭ 
                    xx = (i / 64) % 64 + 128;
                    //������λutf-8����л�ԭ 
                    xxx = i % 64 + 128;
                    printf("%c%c%c 0x%04x %ld\n", x, xx, xxx, i, zi[i]);
 
                }
            }
            
        }
    }
    
    //��ƪ����δ�����ظ��ַ� 
    else
    {
        printf("No repeat!\n");
    }
    
        return 0;
}
