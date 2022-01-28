#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int front=0;
int rear=0;
void Enqueue(int s[], int *rear, int front, int arraySize)
{
    if((*rear-front+1) == arraySize)
            printf("Hang cho da day\n");
    else{
        int n;
        scanf("%d",&n);
        s[*rear]=n;
        (*rear)++;
    }
}
void Dequeue(int s[], int *front, int rear)
{
    if(*front == rear)
        printf("Hang cho da can\n");
    else {
        s[*front]=0;
        (*front)++;
    }
}
int main()
{
    int s[100];
    for(int i=0;i<10;i++){
        Enqueue(s,&rear,front,10);
    }
    printf("%d",s[front]);
    Dequeue(s,&front,rear);
    Enqueue(s,&rear,front,10);
}

