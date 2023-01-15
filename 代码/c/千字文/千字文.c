#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//�����ȡ���� 
	unsigned char read1,read2,read3;
	unsigned char output1,output2,output3;
	//����������
	int result; 
	
	//������ִ��� 
	int array[65536];
	
	//�����־�����������ƪ�����Ƿ����ظ�
	int flag=0; 
	
	//����ѭ������
	int i; 
	
int main()
{
	memset(array,0,sizeof(array));
	
	//�������뼰�洢���� 
	while(~(scanf("%c",&read1)))
	{
		//ascii�� 
		if(read1<128) 
		{
			;
		}
		
		//�����������ֽڱ��� 
		if((read1>=192)&&(read1<224))
		{
			read2=getchar();
			result=((read1&31)<<6)+(read2&63);
			array[result]=array[result]+1; 
			
		}
		
		//�����������ֽڱ��� 
		if((read1>=224)&&(read1<240))
		{
			read2=getchar();
			read3=getchar();
			result=((read1&15)<<12)+((read2&63)<<6)+(read3&63);
			array[result]=array[result]+1; 
		}
	}
	
	//����Ƿ����ظ����ֵĺ��� 
	for(i=0;i<65536;i++)
	{
		if(array[i]>1)
		{
			flag=1;
		}
	}
	
	//û���ظ����ֵĺ���
	if(flag==0)
	{
		printf("No repeat!\n");
	}
	
	if(flag==1)
	{
		for(i=0;i<65536;i++)
		{
			//����ظ� 
			if(array[i]>1)
			{
				//ԭ����λ
				if(i<2048)
				{
					output1=((i&1984)>>6)+192;
					output2=(i&63)+128;
					
					printf("%c%c 0x%04x %d\n",output1,output2,i,array[i]); 
				 } 
				 
				//ԭ����λ
				else
				{
					output1=((i&61440)>>12)+224;
					output2=((i&4032)>>6)+128;
					output3=(i&63)+128;
					
						printf("%c%c%c 0x%04x %d\n",output1,output2,output3,i,array[i]); 
				 } 
				 
				
			}
		}
	}
	
	return 0; 
} 
