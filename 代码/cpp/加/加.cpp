//С�����
#include<stdio.h>
#include<string.h>



int jia(char* s,char* ss,int* a,int* b)     //�Զ��庯��"jia"(����low��һ�㣨������һ�㣬��������ⲻ����) 
{	
	int len;
	int ans;
	int l1 = strlen(s);     //"strlen"��һ�������ַ������ȵĺ��� 
	int l2 = strlen(ss);    //������������ַ����ĳ��ȸ�ֵ��l1,l2
	if (l1 > l2) 
		len = l1;      //��len��ֵΪl1,l2�д���Ǹ� 
	else 
		len = l2;
	//		for (int i = 0 ; i <= len ; i++)  //���㣨����forѭ������������memset��Ϊ���ַ������� �� 
	//			a[i] = b[i] = c[i] = 0;
	memset(a,0,sizeof(a));    //����too(ֻ�����㣬���ܸɱ��) 
	memset(b,0,sizeof(b));    //�������㺯�����ַ����� 
	//����forѭ���ǽ�����������ַ���������
	for (int i = l1 - 1 ; i >= 0 ; i--)    //�ٽ��ַ�������ַ�ת��Ϊ���ָ�ֵ��a,b�������� 
		a[l1 - i - 1] = s[i] - '0';        //��Ϊʲô����Ҫ���ַ������أ�
	for (int i = l2 - 1 ; i >= 0 ; i--)    //��Ϊ����̫�����κ����ͱ������治�� 
		b[l2 - i - 1] = ss[i] - '0';       //ΪʲôҪ���ַ�����������ֵ�أ� 
	//��Ϊ�����������һλһλ����ģ���Ҫ�漰��λ�� 
	for (int i = 0 ; i < len ; i++)
	{
		a[i] = a[i] + b[i];    //���� 
		a[i+1]+= a[i] / 10;    //���н�λ���ں�һλ�ϼ��� 
		a[i] = a[i] % 10;      //ԭ����һλ������λ�˵� 
	}
	if (a[len] != 0) len++;    //����н�λ�Ͷ���ʾһλ����仰����Ҫ�� 
	
	while (a[len - 1] == 0 && len>1) len--;		//�ҽ���whileȥ�㷨
	ans=0;
	for (int i = len - 1 ;i >= 0 ;i--){
		printf("%d",a[i]);//������ 
		b[ans++]=a[i];
	} 
	printf("\n");
	return ans;
}                              //�߾��ȼӷ��㶮����

int main()
{
	char s[1000],ss[1000];
	int a[1000],b[1000];
	int length;
	scanf("%s",s);
	scanf("%s",ss);
	length=jia(s,ss,a,b);
	for(int i=0;i<length;i++){
		printf("%d",b[i]);
	}

	return 0;
}


