#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int timkiem(char y[], char s[])
{
    int n=strlen(y);
    int m=strlen(s);
    int x,a=-1;
    for(int i=0;i<n+1-m;i++){
        x=1;
        for(int j=0;j<m;j++){
            if(y[i+j]!=s[j]){
                x=0;
                break;
            }
        }
        if(x==1){
            a=i;
        }
    }
    printf("%d",a);
    return a;
}
char x,y[1000];
int main(){

    int dem=0;
    fflush(stdin);
    while(1){
        scanf("%c",&x);
        if(x=='#'){
            break;
        }
        y[dem]=x;
        dem++;
    }
    y[dem]='\0';
    printf("%s\n",y);
    timkiem(y,"hoa");
    return 0;
}
