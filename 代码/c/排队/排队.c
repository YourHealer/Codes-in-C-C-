#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����שͷ�߶����� 
int arr[300010];
int arrtmp[300010]; 
	
long long int counter=0;

void _mergesort(int start,int end)
{
	//�ݹ����ֹ������������Ԫ���Ѿ��ǵ���ֵ���޷��١���ȥ�� 
	if(start>=end) return;
	
	//��Ѱ�м�λ�� 
	int mid=start+((end-start)>>1);
	
	//����������Ҷ˵� 
	int istart1=start,iend1=mid;
	//����������Ҷ˵� 
	int istart2=mid+1,iend2=end; 
	
	//������� 
	_mergesort(istart1,iend1);
	_mergesort(istart2,iend2); 
	
	int ii=start;
	
	//����/��������һ��û�кϲ�������ǰ���� 
	while((istart1<=iend1)&&(istart2<=iend2))
	{
		//�������ͨ������������ȡ�ȺžͲ���Ҫ���������Ҫ�������������ͻ��в��ǧ��ע�⣡ 
		if(arr[istart1]<=arr[istart2])
		{
			arrtmp[ii++]=arr[istart1++];
		}
		else
		{
			arrtmp[ii++]=arr[istart2++];
			counter+=(mid+1-istart1);
		}
		
	}
	
	while(istart1<=iend1)
	{
		 arrtmp[ii++]=arr[istart1++];	
	 }
	while(istart2<=iend2) 
	{
		arrtmp[ii++]=arr[istart2++];
	
	}
	
	memcpy(arr+start,arrtmp+start,(end-start+1)*sizeof(int));
}

void mergesort(int len)
{
	//���ֻ��һ��������������ֱ�ӷ��� 
	if(len<2) return;
	
	_mergesort(0,len-1); 
 } 

int main() 
{
	//����שͷ���� 
	int n;

	//��ʼ�� 
	memset(arr,0,sizeof(arr));
	
	//����ѭ������
	int i;
	
	//�������� 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	} 

	//���ú������й鲢���� 
	mergesort(n);
	
	printf("%lld\n",counter); 
	return 0;
}
