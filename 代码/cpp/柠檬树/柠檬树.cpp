#include <iostream>
#include <cmath>
using namespace std;

	int getpos(int m,int h,int cnt){
		//m�ǹ��� h�Ǹ߶�
		if(m==1){
			return 1;
		}
		else if(m==2){
			return pow(2,h-2)+1;
		}
		else{
			if(m>pow(2,h-2-cnt)){
				return (getpos((m-pow(2,h-2-(cnt++))),h,cnt)+pow(2,cnt-1));
			}else{
					return getpos(m,h,++cnt);
				}
		}
	}

//����˼���ǵݹ��㷨
int main() 
{	int a;//�߶�
	int b;//���ӱ��
	int counter=0;
	while(scanf("%d%d",&a,&b)!=EOF){
		int res=getpos(b,a,0);
		printf("Case #%d: %d\n",++counter,res);
	}
	return 0;
}
