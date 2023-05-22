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
{//队列的初始化 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	Q->front->next=NULL;
	return OK;
}
void PQuene(LinkQueue* Q) 
{//判断队列是否为空 
	if(Q->front==Q->rear){
		printf("队列为空。\n");
	}
	else
		printf("队列为非空。\n");	
}
void EnQueue(LinkQueue* Q,int e) 
{//元素入队 
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q->rear->next=p; 
	Q->rear=p;
}
void DeQueue(LinkQueue* Q) 
{//元素出队 
 	if(Q->front==Q->rear)
 	printf("队列为空！");
	int e;
	QueuePtr p;
	p=Q->front->next;
	e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p)
	Q->rear=Q->front;
	free(p);
	printf("出队的元素为：%d\n",e);
}
void LQueue(LinkQueue* Q) 
{//输出队列的长度 
	int length=0;
	QueuePtr p;
	p=Q->front->next;
	while(p){
		length++;
		p=p->next;
	}
	printf("队列的长度为：%d\n",length);
}
void PrintQueue(LinkQueue* Q)
{
	QueuePtr p;
	p=Q->front->next;
	printf("出队序列为：");
	while(p){
		printf("%d  ",p->data);
		p=p->next;
	}
}
int main(){
	LinkQueue q;
	if(InitQueue(&q)==1){
		printf("队列初始化成功！\n");
	}//（1）初始化队列 q；
	PQuene(&q);//（2）判断队列 q 是否为空；
	EnQueue(&q,1);
	EnQueue(&q,12);
	EnQueue(&q,-10);//（3）依次进队列元素 1,12,-10；
	DeQueue(&q);//（4）出队一个元素，并输出该元素；
	LQueue(&q);//（5）输出队列的长度（元素个数）；
	EnQueue(&q,13);
	EnQueue(&q,-12);
	EnQueue(&q,10);//（6）依次进队元素 13,-12,10；
	LQueue(&q);//（7）输出队列长度；
	PrintQueue(&q);//（8）输出出队序列
	return 0; 
}


	


	
