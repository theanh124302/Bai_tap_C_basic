#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int data[100];
	int top;
} Stack;
Stack SX,SY;
void init(Stack *S)
{
	S->top = -1;
}

int isEmpty(Stack *S)
{
	if(S->top == -1){
        return 1;
	}
	else{
        return 0;
	}
}

void Push(Stack *S, int x)
{
	if (S->top == 99)
	{
		printf("\nStack da day");
	}
	else
	{
		++(S->top);
		S->data[S->top] = x;
	}
}

int top(Stack *S)
{
	return (S->data[S->top]);
}

int Pop(Stack *S)
{
	int ret = -1;
	if (S->top == -1)
		printf("\nStack rong");
	else
	{
		ret = S->data[S->top];
		--(S->top);
	}
	return ret;
}
int uutien(char c)
{
    if(c=='^'){
        return 3;
    }
    if(c=='*'||c=='/'){
        return 3;
    }
    if((c=='+')||(c=='-')){
        return 2;
    }
    if((c=='(')||(c==')')){
        return 1;
    }
}
void hamchuyendoi(char a[], char b[])
{
	char x, t;
	int i = 0, j = 0;
	init(&SX);
	for (i = 0; a[i] != '\0'; i++)
	{
		t = a[i];
		if ((int)t>=48&&(int)t<=57)
			b[j++] = t;
		else
			if (t == '(')
				Push(&SX,'(');
			else
				if (t == ')')
					while((x=Pop(&SX))!= '(')
						b[j++] = x;
				else
				{
					while ((uutien(t) <= uutien(top(&SX))) && !isEmpty(&SX))
					{
						x = Pop(&SX);
						b[j++] = x;
					}
					Push(&SX, t);
				}
	}

	while (!isEmpty(&SX))
	{
		x = Pop(&SX);
		b[j++] = x;
	}
	b[j] = '\0';
}

int hamtinh(char b[]){
    int i,x;
    for( i=0 ; b[i]!='\0';i++){
        if(b[i]=='+' || b[i]=='-' || b[i]=='*' || b[i]=='/'){
            int pt1=Pop(&SY);
            int pt2=Pop(&SY);
            if(b[i]=='+'){
                x = pt2 + pt1;
                Push(&SY,x);
            }
            if(b[i]=='-'){
                x = pt2 - pt1;
                Push(&SY,x);
            }
            if(b[i]=='*'){
                x = pt2 * pt1;
                Push(&SY,x);
            }
            if(b[i]=='/'){
                x = pt2 / pt1;
                Push(&SY,x);
            }
        }
        else {
            Push(&SY,((int)b[i]) -48);
        }
    }
    x=Pop(&SY);
    return x;
}


int main()
{
	char A[100], B[100];
	printf("Dau vao : ");
	gets(A);
	hamchuyendoi(A, B);
	printf("Phuong trinh hau to : %s\n", B);
	printf("Ket qua : %d\n", hamtinh(B));
	return 0;
}
