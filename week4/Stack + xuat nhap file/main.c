/*Exercise 4.1 Stack using array
We assume that you make a mobile phone’s address book.
Declare a structure "Address" that can hold at least "name", "telephone number" and "e-mail address".
Write a program that copies data of an address book from a file to another file using a stack.
First, read data of the address book from the file and push them on a stack.
Then pop data from the stack and write them to the file in the order of popped.
In other words, data read first should be read out last and data read last should be read out first.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20],email[20],sdt[20];
} noidung;
noidung fi[30];
typedef struct
{
    noidung st[30];
    int top;
    int kickthuoc;
} stk;
stk S[1];
int n;

int kiemtraday(stk S[]){
    if(S[0].top >= S[0].kickthuoc - 1){
        return 1;
    }else{
        return 0;
    }
}
int kiemtracan(stk S[]){
    if(S[0].top == -1){
        return 1;
    }else{
        return 0;
    }
}
void Push(stk S[],char a[30],char b[30],char c[30]){
    if(kiemtraday(S) == 1){
        printf("\nStack day!");
    }else{
        ++S[0].top;
        strcpy(S[0].st[S[0].top].name,a);
        strcpy(S[0].st[S[0].top].sdt,b);
        strcpy(S[0].st[S[0].top].email,c);
    }
}
void Pop(stk S[]){
    if(kiemtracan(S) == 1){
        printf("\nStack can!");
    }else{
        --S[0].top;
    }
}
char x,y[1000];
int main(){

    int dem1=0,dem2=0,dem3=0;
    FILE *f=fopen("ds.txt","r");
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
    fclose(f);
    S[0].top=-1;
    S[0].kickthuoc=(dem2+1)/3;
    for(int i=0;i<S[0].kickthuoc;i++){
        Push(S,fi[i].name,fi[i].sdt,fi[i].email);
    }
    for(int i=0;i<S[0].kickthuoc;i++){
        printf("ten: %s\nsdt: %s\ngmail: %s\n\n",S[0].st[S[0].top].name,S[0].st[S[0].top].sdt,S[0].st[S[0].top].email);
        Pop(S);
    }

}
