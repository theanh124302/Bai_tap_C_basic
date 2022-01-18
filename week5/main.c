/*Exercise 4-3: Queues Using Lists
•We assume that you write a mobile phone’s address book.
•Declare a structure "Address" that can hold at least "name", "telephone number" and "e-mail address".
•Write a program that copies data of an address book from the file to other file using a queue.
First, read data of the address book from the file and add them to the queue.
Then retrieve data from the queue and write them to the file in the order of retrieved.
In other words, data read in first should be read out first and data read in last should be read out last.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20],email[20],sdt[20];
} st;
st s[30],fi[30];
int n;
int front=0;
int rear=0;
void Enqueue(st s[], int *rear, int arraySize,char a[], char b[], char c[]) {
    if(*rear == arraySize)
            printf("Hang cho da day\n");
    else{
         strcpy(s[*rear].name,a);
         strcpy(s[*rear].sdt,b);
         strcpy(s[*rear].email,c);
         (*rear)++;
    }
}
void Dequeue(st s[], int *front, int rear) {
    if(*front == rear)
        printf("Hang cho da can\n");
    else {
        s[*front].name[0]='\0';
        s[*front].sdt[0]='\0';
        s[*front].email[0]='\0';
        (*front)++;
    }
}





char x,y[1000];
int main(){

    int dem1=0,dem2=0,dem3=0;
    FILE *f=fopen("ds.txt","r+");
    FILE *gg=fopen("daura.txt","r+");
    while(fscanf(f,"%c",&x)!=EOF){
        y[dem1]=x;
        dem1++;
        if(x=='\n'){
            dem3=0;
            dem2++;
        }
        if(dem2%3==0){
            fi[dem2/3].name[dem3]=x;
        }
        if(dem2%3==1){
            fi[dem2/3].sdt[dem3]=x;
        }
        if(dem2%3==2){
            fi[dem2/3].email[dem3]=x;
        }
        dem3++;
    }
    y[dem1]='\0';
    int size=(dem2)/3;
    for(int i=0;i<size;i++){
        Enqueue(s,&rear,size,fi[i].name,fi[i].sdt,fi[i].email);
    }
    for(int i=0;i<size;i++){
        fprintf(gg,"ten: %s\nsdt: %s\ngmail: %s\n",fi[i].name,fi[i].sdt,fi[i].email);
    }
    for(int i=0;i<size;i++){
        Dequeue(s,&front,rear);
    }
    fclose(f);
    fclose(gg);
}
