#include <stdio.h>
#include <string.h>
char s[10000],ss[10000];
int arr[10000];
int cheng_gao(char* s,char* ss,int* d)     //����ָ�߾��ȳ˸߾��� 
{
	int len,lenn;
	int a[10000],b[10000],c[10000];
	len = strlen(s);
	lenn = strlen(ss);
	memset(a,0,sizeof(a));   //��������
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));	
	for (int i = 0 ; i < len ; i++)
		a[len - i - 1] = s[i] - '0';    //���ַ���ת��Ϊ���� 
	for (int i = 0 ; i < lenn ; i++)
		b[lenn - i - 1] = ss[i] - '0';
	
	memset(c,0,sizeof(c));   //���� 
	for (int i = 0 ; i < len ; i++)
		for (int j = 0 ; j < lenn ; j++)
			c[i + j] += a[i] * b[j];       //���㣨�������һ�㸴���ˣ� 
	
	int l = len + lenn - 1;    //l�ǽ�������λ�� 
	for (int i = 0 ; i < l ;i++)
	{
		c[i + 1] += c[i] / 10;    //��֤ÿһλ������ֻ��һλ������λ 
		c[i] %= 10;
	}
	if (c[l] > 0) l++;     //��֤���λ���ǶԵ� 
	while (c[l - 1] >= 10)
	{
		c[l] = c[l - 1] / 10;
		c[l - 1] %= 10;
		l++;
	}
	while (c[l - 1] == 0 && l > 1) 
		l--;    //whileȥ�㷨 
	memcpy(d,c,sizeof(c));
	return l;
}                               


int main()
{
	int len;
	scanf("%s",s);
	scanf("%s",ss);
	len=cheng_gao(s,ss,arr);
	for(int i=len-1;i>=0;i--){
		printf("%d",arr[i]);
	}
	return 0;
}


