#include<stdio.h> 
#include<stdlib.h>
#define MAXSIZE 100
#define OK 1
typedef int status;
typedef struct
{
	char* top;
	char* base;
	int stacksize;
}Sqstack;
status InitStack(Sqstack* S)
{//栈的初始化 
	S->base=(char*)malloc(MAXSIZE*sizeof(char));
	S->top=S->base;
	S->stacksize=MAXSIZE;
	return OK; 
}
void Push(Sqstack* S,char ch)
{//元素入栈 
	if(S->top-S->base==S->stacksize)
		printf("栈已满！"); 
	*S->top=ch;
	S->top++;
}
char Pop(Sqstack* S) 
{//元素出栈 
	char ch;
	S->top--;
	ch=*S->top;
	return(ch);
}
char GetTop(Sqstack* S)
{//取栈顶元素 
	char ch;
	ch=*(S->top - 1);
	return(ch);
}
char Precede(char ch,char t)
{//判断当前元素与栈顶元素的优先级 
	switch(ch)
	{
		case'+':
			switch(t)
			{
				case'+':
				case'-':	
				case')':
				case'#':
					return '>';
				default:
					return '<';
			}
		case'-':
			switch(t)
			{
				case'-':
				case'+':	
				case')':	
				case'#':	
					return '>';
				default:
					return '<';	
			}
		case'*':
			switch(t)
			{
				case'+':
				case'-':
				case'*':
				case'/':
				case')':
				case'#':
					return '>';
				default:
					return '<';
			}
		case'/':
			switch(t)
			{
				case'+':
				case'-':
				case'*':
				case'/':
				case')':
				case'#':
					return '>';
				default:
					return '<';
			}
		case'(':
			switch(t)
			{
				case')':
					return '=';
				default:
					return '<';
			}
		case')':
	         return '>';
	    case'#':
	    	return '<';
	}
}
int main(){
	Sqstack OPTR;
	InitStack(&OPTR);
	Push(&OPTR,'#'); 
	char a[MAXSIZE];
	char b[MAXSIZE];
	int i=0,j=0;
	printf("请输入中缀表达式(以#结束)：");
	gets(a);
	while(a[i]!='#'){
		if(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='('&&a[i]!=')'){
			b[j]=a[i];
			j++;	
		}
		else if(Precede(GetTop(&OPTR),a[i])=='>'){
			b[j]=Pop(&OPTR);
			j++;
			if(Precede(GetTop(&OPTR),a[i])=='='){
				Pop(&OPTR);
			}
			if(Precede(GetTop(&OPTR),a[i])=='>'){
				b[j]=Pop(&OPTR);
				j++;
				if(a[i]!=')')
					Push(&OPTR,a[i]);
			}
			else
				Push(&OPTR,a[i]);
					
		}
		else if(Precede(GetTop(&OPTR),a[i])=='<'){
			Push(&OPTR,a[i]);
		}
		else if(Precede(GetTop(&OPTR),a[i])=='='){
			Pop(&OPTR);
		}
		i++;
	}
	while(GetTop(&OPTR)!='#'){
		b[j]=Pop(&OPTR);
		j++;
	}
	printf("后缀表达式为：");
	puts(b);
	int k=0;
	int ch1,ch3,e,result;
	char ch2;
	Sqstack OPND;
	InitStack(&OPND);
	while(k<j){
		if(b[k]!='+'&&b[k]!='-'&&b[k]!='*'&&b[k]!='/'&&b[k]!='('&&b[k]!=')'){
			Push(&OPND,b[k]);
		}
		else{
			ch2=b[k];
			ch3=Pop(&OPND)-48;
			ch1=Pop(&OPND)-48;
			switch(ch2)
		{
			case'+':
				e=ch1+ch3;break;
			case'-':
				e=ch1-ch3;break;
			case'*':
				e=ch1*ch3;break;
			case'/':
				e=ch1/ch3;break;
			case'%':
				e=ch1%ch3;break;
		}	
		Push(&OPND,e + 48);
		}	
			k++;
	}
	printf("计算结果为：%d",GetTop(&OPND) - 48);
	return 0;
} 

