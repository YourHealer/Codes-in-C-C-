//��������ƶ���ʵ�ڸ�...... �Ƚ�Σ�� ���Կ����޸�һ��������� ����λ����ĺ����㷨��Ҳ�����ڲ��ֲ��账�Լ���һЩ�����㷨~ 
 
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int num[100000];
int a[20][20],aa[20][20];

//���� 
void re(int *q){
 if(*q==1) *q=0;
 else      *q=1; 
  
}
//�޸ĵƵ�״̬ 
void di(int i,int j)
{
    re(&aa[i][j]);
 	re(&aa[i+1][j]);
    re(&aa[i-1][j]);
    re(&aa[i][j+1]);
    re(&aa[i][j-1]);
}




int compare(int s,int qum[]){
 int min=0;
 int i;
 for(i=0;i<s-1;i++){
   if(*(qum+min)>*(qum+i)) min=i;
 }
 return min;
}
int main()
{

 int i,j,m,n,p;
 long int s;
 int cnt,k,result;
 
 scanf("%d %d",&m,&n);
 
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
  //�޸ĵ�1 �㿴�������� ��һ����ֱ�Ӹ� ������ڸ�ʽ������������������ĳ���Ϊ1 ��ֱ�Ӱ�һ����������һ�������뵽һ���������� 
   scanf("%1d",&a[i][j]);
  }
 }//��������
  
  s=pow(2,n);
  
  for(k=0;k<s;k++){    
  
   cnt=0; 
  
  for(i=0;i<m;i++)
  {
  for(j=0;j<n;j++)
  {
  	//�޸ĵ�2 ����������ʲô ��ԭ��д����==��==��if���ж���� ����Ϊ=����˵���Ե�ʱ��aaû���� ȫ��0 ��û�и���ֵ 
    aa[i][j]=a[i][j];
   
  }
 }

  for(j=0;j<n;j++)
  {
    if((k>>j)&1){
    cnt++;
 //�޸ĵ�3 ������n-j-1������n-j+1  
    di(0,n-j-1);
     }
  }
  //��һ����� 
  //kָ�ڵ�һ�еĲ������� 
 
  for(i=0;i<m-1;i++){
   for(j=0;j<n;j++){
    if(aa[i][j]==1){
     di(i+1,j);
     cnt++;
    }
   }
  }
 //���в��� 
p=0;
    
 for(j=0;j<n;j++)
  if(aa[m-1][j]==1)p=1;
//�޸ĵ�4 ���100000����ԭ����㸳ֵ�� �㹻��ͺ�  ������ȡ�������ͺ� 
 if(p==0){num[k]=cnt;}
   else{num[k]=3000;}
 
 
 
 }

  result=compare(s,num);
   printf("%d\n",num[result]);
   
   return 0;
   
}

