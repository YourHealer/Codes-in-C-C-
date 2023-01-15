#include <stdio.h>
#include <stdlib.h>
#define people 2
#define subject 3
int score[people][subject];

int main() 
{
	int average_student(int mark);
	int average_subject(int mark);
	void find_max(int array[people][subject]);
	int add();
	int square_add();
	int variance();
	
	int i,j;
	for(i=0;i<people;i++)
	{
		for(j=0;j<subject;j++)
		{
			scanf("%d",&score[i][j]);
		}
	}
	
/*����ÿ��ѧ����ƽ����*/
    for(i=0;i<people;i++)
	{
		printf("��%d��ѧ���ĳɼ�Ϊ��%d��\n",i+1,average_student(i));
    }	
    
/*����ÿ��ѧ�Ƶ�ƽ����*/
    for(i=0;i<subject;i++)
	{
	    printf("��%d��ѧ�Ƶĳɼ�Ϊ��%d��\n",i+1,average_subject(i));
	} 
    
/*����߷�*/
    find_max(score); 
    
/*��ƽ���ַ���*/
    printf("ƽ���ַ���Ϊ��%d��\n",variance());

	return 0;
}



/*��ÿ��ѧ����ƽ����*/
int average_student(int mark) 
{
	int sum=0;
	int i; 
	for(i=0;i<subject;i++)
	{
		sum=sum+score[mark][i];
	}
	int aver;
	aver=sum/subject;
	
	return(aver);
}

/*��ÿ��ѧ�Ƶ�ƽ����*/
int average_subject(int mark)
{
	int sum=0;
	int i; 
	for(i=0;i<people;i++)
	{
		sum=sum+score[i][mark];
	}
	int aver;
	aver=sum/people;
	
	return(aver);
}

/*����߷ֶ�Ӧ��ϵ*/
void find_max(int array[people][subject])
{
	int i=0;
	int j=0;
	int mark_i=0;
	int mark_j=0;
	int max=array[i][j];
	
	for(i=0;i<people;i++)
	{
		for(j=0;j<subject;j++)
		{
			if(array[i][j]>max)
			{
				mark_i=i;
				mark_j=j;
			}
		}
	}
	
	printf("��߷��ǵ�%d��ͬѧ�ĵ�%d�ſΡ�\n",mark_i+1,mark_j+1);
}

/*��ѧ��ƽ�����ܺ�*/
int add()
{
	int sum=0;
	int i;
	for(i=0;i<people;i++)
	{
		sum=sum+average_student(i);
    }	
	return(sum);
} 


/*����ƽ����*/
int square_add()
{
	
	int sum=0;
	int i;
	for(i=0;i<people;i++)
	{
		sum=sum+average_student(i)*average_student(i);
    }	
	return(sum);
}

/*��ƽ���ַ���*/
int variance()
{
	int sigma;
	sigma=square_add()/people-(add()/people)*(add()/people);
	
	return(sigma);
 } 
 
