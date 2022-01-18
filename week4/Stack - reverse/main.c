//Test the "stack" type that you've defined in a program that read from user a string, then reverse it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char a[30];
    int top;
    int kickthuoc;
} st;
st S[1];
int n;
int kiemtraday(st S[]){
    if(S[0].top >= S[0].kickthuoc - 1){
        return 1;
    }else{
        return 0;
    }
}
int kiemtracan(st S[]){
    if(S[0].top == -1){
        return 1;
    }else{
        return 0;
    }
}
void Push(st S[],char c){
    if(kiemtraday(S) == 1){
        printf("\nStack day!");
    }else{
        ++S[0].top;
        S[0].a[S[0].top]=c;
    }
}
void Pop(st S[]){
    if(kiemtracan(S) == 1){
        printf("\nStack can!");
    }else{
        --S[0].top;
    }
}
int main(){
    char ch[30];
    printf("nhap chuoi: ");
    gets(ch);
    S[0].top=-1;
    S[0].kickthuoc=strlen(ch);
    for(int i=0;i<S[0].kickthuoc;i++){
        Push(S,ch[i]);
    }
    for(int i=0;i<S[0].kickthuoc;i++){
        printf("%c",S[0].a[S[0].top]);
        Pop(S);
    }
}
