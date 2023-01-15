/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* head;

void Insert(int num);
void Reverse(Node* pointer);
void Print();

int main() 
{
	head=NULL;
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Reverse(head);
	Print();
	return 0;
}

void Insert(int num)
{
	Node* temp1=(Node*)malloc(sizeof(Node));
	
	temp1->data=num;
	temp1->next=NULL;
	
	if(head==NULL)
	{
		head=temp1;
	}
	else
	{
		Node* temp2=head;
		while(temp2->next!=NULL)
		{
			temp2=temp2->next;
		}
		temp2->next=temp1;
	}
}

void Print()
{
	Node* temp1=head;
	while(temp1!=NULL)
	{
		printf("%d ",temp1->data);
		temp1=temp1->next;
    }
}

void Reverse(Node* pointer)
{
	if(pointer->next==NULL)
	{
		head=pointer; 
		return;
	}
	Reverse(pointer->next);
	Node* temp2=pointer->next;
	temp2->next=pointer;
	pointer->next=NULL;
	
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* temp;

Node* Insert(int num,Node* pointer);
Node* Reverse(Node* pointer);
void Print(Node* pointer);

int main() 
{
    Node* head=NULL;
	head=Insert(1,head);
	head=Insert(2,head);
	head=Insert(3,head);
	head=Insert(4,head);
	head=Insert(5,head);
	head=Reverse(head);
	Print(head);
	return 0;
}

Node* Insert(int num,Node* pointer)
{
	Node* temp1=(Node*)malloc(sizeof(Node));    //�����½ڵ� 

	temp1->data=num;
	temp1->next=NULL;                           //����ڵ����ݣ�������nextΪ��ָ�� 
	
	if(pointer==NULL)                           //��ͷָ��Ϊ�գ�˵��ԭ�����ﻹû�нڵ� ����ͷָ��ָ��ýڵ� 
	{
		pointer=temp1;
	}
	else                                        //��ͷָ�벻Ϊ�գ�˵��ԭ�������н�㣬��ͨ��ѭ��ָ��ԭ�������һ���ڵ㣬ʹ�ýڵ�ָ�򱾽ڵ� 
	{
		Node* temp2=pointer;
		while(temp2->next!=NULL)
		{
			temp2=temp2->next;
		}
		temp2->next=temp1;
	}
	return(pointer);                           //����ͷָ��ֵ 
}

void Print(Node* pointer)                      //����ѭ����ͷ��β��������������ڵ������ 
{
	Node* temp1=pointer;
	while(temp1!=NULL)
	{
		printf("%d ",temp1->data);
		temp1=temp1->next;
    }
}


Node* Reverse(Node* pointer)
{

	if(pointer->next==NULL)
	{
	
		temp=pointer;
		return;
	}
	Reverse(pointer->next);
	Node* temp2=pointer->next;
	temp2->next=pointer;
	pointer->next=NULL;
	return(temp);
}

