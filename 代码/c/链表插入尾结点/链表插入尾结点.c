#include<stdio.h>
#include<stdlib.h>
typedef struct book
{
	int num;				//ͼ����
	float price;			//ͼ��۸�
	struct book *next;		//ָ����һ���ڵ��ָ��
}Book;
Book *head=NULL;			//��ʼ��ͷָ��Ϊ��
int n=0;					//�ܽڵ���Ŀ

//��̬��ӽڵ�
void Create()
{
	Book *p=NULL;				//���ڱ�������
	Book *p_new=NULL;			//�洢�½ڵ�ĵ�ַ
	Book *p_old=NULL;			//�洢β�ڵ�ĵ�ַ
	int num;				//�����û�����ı��
	if (head!=NULL)
	{
		p=head;
		while (p!=NULL)
			p=p->next;
		p_old=p;			//������������н�㣬����ѭ����������ʱ����β�ڵ��ַ���档�����������û�н�㣬 β����ַ��ΪNULL�� 
	}
	while (1)
	{reInput:
		printf("������ͼ���ţ���0������");
		scanf("%d",&num);
		if (num==0)
		{
			getchar();		//���������Enter��
			break;
		}
		p=head;				//���ͷָ�룬���ڱ���
		while (p!=NULL)
		{
			if (p->num==num)
			{
				printf("����ظ������������롣\n");
				goto reInput;
			}
			p=p->next;		//����ѭ��������������뵱ǰͼ�����Ƿ��ظ������ظ��������룬�����ظ���ȡ��һ���ڵ�ĵ�ַ����Ƿ��ظ��� 
		}
		p_new=(Book*)malloc(sizeof(Book));	//�����½ڵ�
		p_new->num=num;		//������
		n++;				//�ܽڵ���+1
		if (n==1)
		{
			head=p_new;
		}
		else
		{
			p_old->next=p_new;
		}
		p_old=p_new;
		p_new->next=NULL;
		printf("������ͼ��۸�");
		scanf("%f",&p_new->price);
	}
}

//��ʾ���нڵ�����
void Show()
{
	Book *p;
	p=head;
	if (p==NULL)
	{
		printf("û��ͼ����Ϣ��\n");
		return;
	}
	printf("ͼ����\tͼ��۸�\n");
	while (p!=NULL)
	{
		printf("%d\t\t%.2f\n",p->num,p->price);
		p=p->next;
	}
}
int main()
{
	Create();//��̬��ӽڵ�
	Show();//��ʾ���нڵ�����
	return 0;
}


