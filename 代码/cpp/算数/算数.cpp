#include<stdio.h>
int main(){
	char a,b,c;//���ձ���
	int max=0,min=10000,res=0;//��Сֵ�����ֵ�����
	int flag=0;//��ʶ����
	
	//����ѭ����ȡ�����Сֵ�������յ���a����Ϊ�����
	while(scanf("%c%c",&a,&b)){
		if((a>='0')&&(a<='9')){
			if(max<a){
				max=a;
			}
			if(min>a){
				min=a;
			}
		}else break;
	}
	//���ַ�����ת��Ϊ���ͱ���
	max-=48;
	min-=48;
	
	//���յȺ�
	scanf("%c",&c);
	
	//����������з�֧�ж�
	if(a=='+'){
		res=max+min;
	}else if(a=='-'){
		res=max-min;
	}else if(a=='*'){
		res=max*min;
	}else if(a=='/'){
		//�Գ����г���Ϊ0���ر�����ʶ�����ı�
		if(min==0){
			printf("Error!\n");
			flag=1;
		}else{
			res=max/min;	
		}
	}else if(a=='%'){
		res=max%min;
	}
	
	//���ݱ�ʶ�����Խ���������
	if(!flag){
		printf("%d%c%d%c%d\n",max,a,min,c,res);
	}
	
}
