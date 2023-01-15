#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int tower[200005];//������
//amo��ÿ��ȡ����Ʒ�� �ܹ�ʵ���������Сamo��Ϊans len��tower�ĳ��� mom�����������ʣ��ʱ��
bool tryandtry(int amo,int len,int mom){
		int cnt=0;
		//����ÿ�������б����������˴���
		for(int t=0;t<len;t++)
		{
			cnt+=ceil(tower[t]*1.0/amo);
		}
		//�ж��ܷ�����������֮ǰ����
		if(cnt<=mom)
		{
			return true;
		}
		else
		{
			return false;
		}
}

int cutinhalf(int left,int right,int n,int k){
	int mid=ceil(left+0.5*(right-left));
	if((right-left)<=1)
	{
	 	return right;
	}
	else
	{
	 	if(tryandtry(mid,n,k))
		{
	 		return cutinhalf(left,mid,n,k);
	 	}
		else
		{
	 		return cutinhalf(mid,right,n,k);
	 	}
	}
}

int main() 
{
	int times=0;//����
	int n,k;//��������������ؼҵ�ʣ��ʱ��

	int max_length=0;
	scanf("%d",&times);
	
	//����ÿ������ѭ��
	for(int i=0;i<times;i++){
		scanf("%d%d",&n,&k);
		memset(tower,0,sizeof(tower));
		
		//����ÿ��������������
		for(int j=0;j<n;j++){
			scanf("%d",&tower[j]);
		}
		
		//���������ֵ
		for(int u=0;u<n;u++){
			if(tower[u]>max_length){
				max_length=tower[u];
			}
		}
		
		if(tryandtry(max_length,n,k)){
			printf("%d\n",cutinhalf(0,max_length,n,k));
		}else{
			printf("QAQ\n");
		}
		
	}
	return 0;
}
