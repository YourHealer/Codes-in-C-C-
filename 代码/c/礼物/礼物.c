#include<stdio.h>
#include<string.h>
#include<stdbool.h>//���벼���� 
#include<limits.h>//���뼫�� 
#define XLEN 200010//��ѡ�� 
#define WORDLEN 10010//��ѡ�� 

// freopen("input.txt", "r", stdin); //0 �����ض���

char x[XLEN]; //x�����ɸѡ�ַ���

bool used[XLEN];//used������¼�ַ��Ƿ��Ѿ���ʹ�ù�

char words[WORDLEN * 2]; //words��������Ϊ�˷�����

int next[XLEN][26];//next����꣬�������Զ�����������int�� ���������λ�� 

int ans[WORDLEN]; //ans�������Ž� 

int temp[WORDLEN]; //temp����ͨ��

int i,j,k; //ijk��������ѭ��

int main(void)
{
 int len_x, len_word;//�����ַ������� 
 
 len_word = strlen(words);//�� 
 len_x = strlen(x);//��
 
 memset(next, -1, sizeof(next)); //����ʼ��Ϊ-1 ,���ڴӺ������ֵʱ����ȷ��߾��޸���ĸ 
 
 scanf("%s%s", x, words);//���� 
 

  
 for (i=0; i<len_word; i++)
  ans[i] = INT_MAX; //��ʼ���ֵ���������ֵ��� �ض������ڵ�һ�αȽ�ʱ���� 
  
 strncat(words, words, 2*WORDLEN-len_word-1); //��˫��������
 
 //���������Զ��� next[i][j]=k ��ʾ��ǰ���������д���iλ���ϵ���һ�����j��ĸ������λ��Ϊk 

 //i��strlen-1��0������
 
 //���鿪�����Բ���Խ�磬���ǳ�ʼ��ֵ 

 
 for (i=len_x-1; i>=0;i--) 
 {
  for (j=0; j<26; j++) 
  {
  		next[i][j] = next[i+1][j];
  }
   
   
  	next[i][x[i] - 'a'] = i;
 }
 
 //�����л�������
 for (i = 0; i < len_word; i++)
 {
 	//��ÿ������������лָ���ʼ�趨
	  
  int node = 0; //��һ�������������ͷ������β��
  int k = 0;//k�����������λ��
  bool isloop = true; //ÿ�μ�����Գɻ�
  bool isbetter = true; //����ÿ�ζ��Ǹ��Ž�
  memset(used, 0, sizeof used); //ÿ�ζ�Ҫˢ��ʹ�����
  
  
  	for (j = 0; j < len_word; j++)
  	{
   		if (used[node]) //����������ǰλ�ô�����Ӱ��
   		{
   		node++;
		} 
		
   		node = next[node][words[i + j] - 'a'];
  		temp[k++] = node + 1;//+1�ʹ����ʵ��λ��
   		used[node] = true;
   		
  		 if (node == -1) //����û����
   		{
   		 isloop = false;//���ܳɻ� 
    	 break;
  		}
   
  }
  
 	 if (isloop) //�ɹ�����һȦ,temp�Ѿ�װ�ã��������Ž�
  	{
   //�Ƚ��ֵ�����Ϊ�õ�INT_MAX,��һ�αȽϱض��ɹ�
   		for (k = 0; k < len_word; k++)
   		{  
    		if (temp[k] > ans[k])
   		    {
     		isbetter = false;
     		break;
    		}
    		else if (temp[k] < ans[k])
    			{	
				break;
		    	}
   		
  		}
 
   //�������ǰ�˳����ƣ�����ͱ��� temp 2 5 9 10��  ans 2 6 8 9
   //��Ȼû����ǰ�˳�������9>8�����ж��ֵ���С
   //��������ǻ������Σ��Ƚ��ֵ���Ӧ���ǻ��������ֳ��������
   //һ��������һ����ֱ���жϳ�������ȲŽ�����һ��
   //�����ǰ���������������ʵĺϲ�
   			if (isbetter)
			{//�Ǹ��Ž���д��ans
    			for (k = 0; k < len_word; k++)
   				 { 
	 				ans[k] = temp[k];
				 }
			}
    }
 }
// printf("���Ž�:"); //3 ����
 for (i = 0; i < len_word; i++)//��������k�ģ��Ͼ�k������Ǵ�λ�õģ�����k���ͷ���
  printf("%d%c",ans[i],i==len_word-1?'\n':' ');
 
 return 0;
}


