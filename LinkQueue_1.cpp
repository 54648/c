#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
int InitQueue(LinkQueue* Q)
{//���еĳ�ʼ�� 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	Q->front->next=NULL;
	return OK;
}
void PQuene(LinkQueue* Q) 
{//�ж϶����Ƿ�Ϊ�� 
	if(Q->front==Q->rear){
		printf("����Ϊ�ա�\n");
	}
	else
		printf("����Ϊ�ǿա�\n");	
}
void EnQueue(LinkQueue* Q,int e) 
{//Ԫ����� 
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q->rear->next=p; 
	Q->rear=p;
}
void DeQueue(LinkQueue* Q) 
{//Ԫ�س��� 
 	if(Q->front==Q->rear)
 	printf("����Ϊ�գ�");
	int e;
	QueuePtr p;
	p=Q->front->next;
	e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p)
	Q->rear=Q->front;
	free(p);
	printf("���ӵ�Ԫ��Ϊ��%d\n",e);
}
void LQueue(LinkQueue* Q) 
{//������еĳ��� 
	int length=0;
	QueuePtr p;
	p=Q->front->next;
	while(p){
		length++;
		p=p->next;
	}
	printf("���еĳ���Ϊ��%d\n",length);
}
void PrintQueue(LinkQueue* Q)
{
	QueuePtr p;
	p=Q->front->next;
	printf("��������Ϊ��");
	while(p){
		printf("%d  ",p->data);
		p=p->next;
	}
}
int main(){
	LinkQueue q;
	if(InitQueue(&q)==1){
		printf("���г�ʼ���ɹ���\n");
	}//��1����ʼ������ q��
	PQuene(&q);//��2���ж϶��� q �Ƿ�Ϊ�գ�
	EnQueue(&q,1);
	EnQueue(&q,12);
	EnQueue(&q,-10);//��3�����ν�����Ԫ�� 1,12,-10��
	DeQueue(&q);//��4������һ��Ԫ�أ��������Ԫ�أ�
	LQueue(&q);//��5��������еĳ��ȣ�Ԫ�ظ�������
	EnQueue(&q,13);
	EnQueue(&q,-12);
	EnQueue(&q,10);//��6�����ν���Ԫ�� 13,-12,10��
	LQueue(&q);//��7��������г��ȣ�
	PrintQueue(&q);//��8�������������
	return 0; 
}


	


	
